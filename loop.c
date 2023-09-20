#include "shell.h"

/**
 * hsh - main shell loop
 * @info: parameter return info struct
 * @av: the argument vector from main()
 * Return: 0 success, 1 error
 */
int hsh(info_t *info, char **av)
{
ssize_t r = 0;
int builtin_ret = 0;
do {
clear_info(info);
if (active(info))
_puts("$ ");
_eputchar(BUF_FLUSH);
r = get_input(info);
if (r != -1)
{
set_info(info, av);
builtin_ret = find_builtin(info);
if (builtin_ret == -1)
cfind(info);
}
else if (active(info))
_putchar('\n');
free_info(info, 0);
} while (r != -1 && builtin_ret != -2);
past_write(info);
free_info(info, 1);
if (!active(info) && info->status)
exit(info->status);
if (builtin_ret == -2)
{
if (info->err_num == -1)
exit(info->status);
exit(info->err_num);
}
return (builtin_ret);
}

/**
 * find_builtin - it checks a builtin command
 * @info: parameter, return info struct
 * Return: -1 if builtin not found,
 * 0 executed successfully,
 * 1 found but not successful,
 * 2 exit()
 */
int find_builtin(info_t *info)
{
int i, built_in_ret = -1;
builtin_table builtintbl[] = {
	{"exit", check_exit},
	{"env", __env},
	{"help", check_help},
	{"history", past_histori},
	{"setenv", __setenv},
	{"unsetenv", __unsetevv},
	{"cd", check_cd},
	{"alias", _myalias},
	{NULL, NULL}
};

for (i = 0; builtintbl[i].type; i++)
if (_strcmp(info->argv[0], builtintbl[i].type) == 0)
{
info->line_count++;
built_in_ret = builtintbl[i].func(info);
break;
}
return (built_in_ret);
}

/**
 * cfind - finds a command in PATH
 * @info: the parameter & return info struct
 *
 * Return: void
 */
void cfind(info_t *info)
{
char *p = NULL;
int i, j;
info->path = info->argv[0];
if (info->linecount_flag == 1)
{
info->line_count++;
info->linecount_flag = 0;
}
for (i = 0, j = 0; info->arg[i]; i++)
if (!_isdelim(info->arg[i], " \t\n"))
j++;
if (!j)
return;
p = fi_ndpath(info, _getenv(info, "PATH="), info->argv[0]);
if (p)
{
info->path = p;
cfork(info);
}
else
{
if ((active(info) || _getenv(info, "PATH=")
|| info->argv[0][0] == '/') && is_cmd(info, info->argv[0]))
cfork(info);
else if (*(info->arg) != '\n')
{
info->status = 127;
print_error(info, "not found\n");
}
}
}

/**
 * cfork - it forks exec thread to run cmd
 * @info: parameter, return info struct
 * Return: nothing
 */
void cfork(info_t *info)
{
pid_t child_pid;
child_pid = fork();
if (child_pid == -1)
{
/* TODO: ERROR FUNCTION */
perror("Error:");
return;
}
if (child_pid == 0)
{
if (execve(info->path, info->argv, get_environ(info)) == -1)
{
free_info(info, 1);
if (errno == EACCES)
exit(126);
exit(1);
}
/* TODO: ERROR FUNCTION */
}
else
{
wait(&(info->status));
if (WIFEXITED(info->status))
{
info->status = WEXITSTATUS(info->status);
if (info->status == 126)
print_error(info, "Permission denied\n");
}
}
}


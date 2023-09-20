#include "shell.h"

/**
 * check_exit - exits the shell
 * @info: Structure containing potential arguments. Used to maintain
 * constant function prototype.
 * Return: exits with a given exit status
 * (0) if info.argv[0] != "exit"
 */
int check_exit(info_t *info)
{
int exitcheck;
exitcheck = (info->argv[1]) ? _erratoi(info->argv[1]) : -1;
if (exitcheck == -1)
{
info->status = 2;
print_error(info, "Illegal number: ");
_eputs(info->argv[1]);
_eputchar('\n');
info->err_num = exitcheck;
return (1);
}
info->err_num = exitcheck;
return (-2);
}

/**
 * check_cd - changes the cd of the process
 * @info: Structure containing potential arguments
 * Return: Always 0
 */
int check_cd(info_t *info)
{
char *s, *dir, buffafer[1024];
int chdir_ret;
s = getcwd(buffafer, 1024);
if (!s)
_puts("TODO: >>getcwd failure emsg here<<\n");
if (!info->argv[1]) {
dir = _getenv(info, "HOME=");
if (!dir)
{
chdir_ret = chdir((dir = _getenv(info, "PWD=")) ? dir : "/");
}
else
{
chdir_ret = chdir(dir);
}
}
else if (_strcmp(info->argv[1], "-") == 0)
{
if (!_getenv(info, "OLDPWD="))
{
_puts(s);
_putchar('\n');
return 1;
}
_puts(_getenv(info, "OLDPWD=")), _putchar('\n');
chdir_ret = chdir((dir = _getenv(info, "OLDPWD=")) ? dir : "/");
}
else
{
chdir_ret = chdir(info->argv[1]);
}
chdir_ret == -1 ? (print_error(info, "can't cd to "),
_eputs(info->argv[1]), _eputchar('\n'))
: (_setenv(info, "OLDPWD", _getenv(info, "PWD=")),
_setenv(info, "PWD", getcwd(buffafer, 1024)));
return 0;
}

/**
 * check_help - changes the cd of the process
 * @info: Structure containing potential arguments
 * Return: Always 0
 */
int check_help(info_t *info)
{
char **arg_array;
arg_array = info->argv;
_puts("help call works. Function not yet implemented \n");
if (0)
_puts(*arg_array);
return (0);
}

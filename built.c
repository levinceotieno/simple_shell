#include "shell.h"

/**
 * cd_only - function to change current working directory
 * @varComnd: command variables
 * Return: status
 */

int cd_only(cmd_t varComnd)
{
int status = 0;
int st;
char *dir_name = varComnd.cmd[1];
char buff[1024];
if (dir_name == NULL)
dir_name = _getenv("HOME");
else
{
if (_strcmp(dir_name, "-") == 0)
{
dir_name = _getenv("OLDPWD");
setenv("OLDPWD", (const char *)getcwd(buff, 1024), 1);
write(STDOUT_FILENO, dir_name, _strlen(dir_name));
write(STDOUT_FILENO, "\n", 1);
}
st = chdir((const char *)dir_name);
}
st = chdir((const char *)dir_name);
/* checks for permissions or existence of directory */
if (st == -1)
{
dprintf(STDERR_FILENO, "%s: %d: cd: can't cd to %s\n",
varComnd.prg_name, varComnd.cmd_no, dir_name);
varComnd.status = errno;
status = errno;
return (status);
}
setenv("PWD", dir_name, 1);
return (status);
}

/**
 * trueNum - checks a string if it contains a non-int character
 * @string: string to check
 * Return: 1 if true, 0 otherwise
 */

int trueNum(char *string)
{
do {
if (_isdigit(*string) == 0)
return (0);
string++;
} while (*string);
return (1);
}

/**
 * __exit - terminates a process
 * @varComnd: command variables
 * Return: status
 */

int __exit(cmd_t varComnd)
{
char error_msg[] = "Illegal number: ";
int exit_status = varComnd.status;

if (varComnd.cmd[1] != NULL)
{
if (trueNum(varComnd.cmd[1]))
{
exit_status = _atoi(varComnd.cmd[1]);
if (exit_status < 0)
{
random_prnt(varComnd.cmd_no, varComnd.prg_name, varComnd.cmd[0], error_msg);
_puts(varComnd.cmd[1], STDERR_FILENO);
_puts("\n", STDERR_FILENO);
return (2);
}
else
{
twodfre(varComnd.cmd);
exit(exit_status);
}
}
else
{
random_prnt(varComnd.cmd_no, varComnd.prg_name, varComnd.cmd[0], error_msg);
_puts(varComnd.cmd[1], STDERR_FILENO);
_puts("\n", STDERR_FILENO);
return (2);
}
}
twodfre(varComnd.cmd);
exit(exit_status);
}
/**
 * _isdigit - checks for digit 0-9
 * @c: int character
 * Return: 1 if c is a digit else 0
 */

int _isdigit(int c)
{
int result;

if (c >= 48 && c < 58)
result = 1;
else
result = 0;
return (result);
}


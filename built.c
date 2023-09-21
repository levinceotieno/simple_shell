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
 * _isdigit - checks for digit 0-9
 * @c: int character
 * Return: 1 if c is a digit else 0
 */

int _isdigit(int c)
{
return ((c >= 48 && c < 58) ? 1 : 0);
}


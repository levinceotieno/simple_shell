#include "shell.h"
/**
 * run_cmd - __execute__s command based on arguments passed
 * @varComnd: struct of command variables
 * Return: status
 */

int run_cmd(cmand_t varComnd)
{
pid_t child;
char *_command;
int st;
_command = _which(varComnd.cmd[0]);

if (_command == NULL)
{
random_prnt(varComnd.cmand_no, varComnd.f_name, varComnd.cmd[0],
"not found\n");
varComnd.status = 127;
return (1);
}
else
{
child = fork();
if (child == -1)
{
perror("Child process failed\n");
return (1);
}
}
if (child == 0)
{
st = execve(_command, varComnd.cmd, varComnd.env);
if (st == -1)
{
random_prnt(varComnd.cmand_no, varComnd.f_name, varComnd.cmd[0],
strerror(errno));
}
}
else
{
wait(&varComnd.status);
if (_command != varComnd.cmd[0])
{
free(_command);
}
}
return (WEXITSTATUS(varComnd.status));
}

/**
 * non_interactive - runs in the non interactive mode
 * @buffer: buffer storing the characters read in a line stream
 * @n: number of bytes read
 * @file: a file to be read from
 * @varComnd: command variables
 * Return: status
 */
int non_interactive(char **buffer, size_t *n, FILE *file, cmand_t varComnd)
{
int status = 0;
while (getline(buffer, n, file) != -1)
{
if (_strlen(*buffer) <= 1 || _strspn(*buffer, " \t\n")
== (size_t)_strlen(*buffer) || *(buffer[0]) == '#')
continue;
varComnd.cmd = tokenize(*buffer, _DELIM);
if (varComnd.cmd == NULL)
{
perror("tokenize failed");
exit(1);
}
varComnd.cmand_no += 1;
status = __execute__(varComnd);
varComnd.status = status;
}
free(*buffer);
return (status);
}


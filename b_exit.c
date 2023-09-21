#include "shell.h"
/**
 * __exit - terminates a process
 * @varComnd: command variables
 * Return: status
 */
int __exit(cmd_t varComnd)
{
int trueNum(char *string);
char error_msg[] = "Illegal number: ";
int exit_status = varComnd.status;
if (varComnd.cmd[1] != NULL)
{
if (trueNum(varComnd.cmd[1]))
{
exit_status = _atoi(varComnd.cmd[1]);
if (exit_status < 0)
{
random_prnt(varComnd.cmd_no, varComnd.prg_name,
varComnd.cmd[0], error_msg);
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
random_prnt(varComnd.cmd_no, varComnd.prg_name,
varComnd.cmd[0], error_msg);
_puts(varComnd.cmd[1], STDERR_FILENO);
_puts("\n", STDERR_FILENO);
return (2);
}
}
twodfre(varComnd.cmd);
exit(exit_status);
}


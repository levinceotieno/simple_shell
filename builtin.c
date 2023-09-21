#include "shell.h"

/**
 * get_builtin - get specific builint funct
 * @b_cmd: builtin command
 * Return: function ptr 2 specific function else NULL
 */
int (*get_builtin(char **b_cmd))(cmand_t varComnd)
{
int i = 0;
/* array of funct points */
built_t ops[] = {
	{"cd", cd_only},
	{"exit", __exit},
	{"env", _env}
};
while (i < 3)
{
if (strcmp(b_cmd[0], ops[i].cmand_n) == 0)
{
return (ops[i].cmd);
}
i++;
}
return (NULL);
}


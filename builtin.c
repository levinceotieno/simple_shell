#include "shell.h"

/**
 * get_builtin - get specific builint funct
 * @b_cmd: builtin cmd
 * Return: funct ptr 2 specific function else NULL
 */
int (*get_builtin(char **b_cmd))(cmand_t varComnd)
{
int i = 0;
/* array of funct */
built_t ops[] = {
	{"cd", cd_only},
	{"exit", __exit},
	{"env", _env}
};
do {
if (strcmp(b_cmd[0], ops[i].cmand_n) == 0)
{
return (ops[i].cmd);
}
i++;
} while (i < 3);
return (NULL);
}


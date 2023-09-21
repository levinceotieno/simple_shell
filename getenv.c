#include "shell.h"

/**
 * _getenv - searchs 4 a variable in the environ vars
 * @var: variable to look for
 * Return: pointer to variable (string)
 */
char *_getenv(char *var)
{
char *result;
char **environ_ment = environ;
int i = 0, len_var = _strlen(var);
while (1)
{
if (environ_ment[i] == NULL)
break;
result = _strstr(environ_ment[i], var);

if (result != NULL && result[len_var] == '=' && result ==
environ_ment[i])
return (result + len_var + 1);
i++;
}
return (NULL);
}

/**
 * _env - printing the environment variables of an environ
 * @varComnd: command variables
 * Return: returns exit_status
 */
int _env(cmand_t varComnd)
{
int i;
for (i = 0; varComnd.env[i]; i++)
{
write(STDOUT_FILENO, varComnd.env[i], _strlen(varComnd.env[i]));
write(STDOUT_FILENO, "\n", 1);
}
if (varComnd.cmd == NULL)
{
return (2);
}
return (0);
}


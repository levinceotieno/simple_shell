#include "shell.h"
/**
 * we_setenv - appends or overwrites envir
 * @name: variable name
 * @value: variable value
 * @overwrite: overwriting option
 * Return: 0 on success else 1
 */
int we_setenv(const char *name, const char *value, int overwrite)
{
char *variable;
int len_name = _strlen((char *)name),
len_value = _strlen((char *)value), i;
variable = malloc(sizeof(char) * (len_value + len_name + 2));
if (!variable)
{
free(variable);
perror("Not enough memory");
return (1);
}
__enter(variable, (char *)name, (char *)value, "=");
if (!_getenv((char *)name))
{
for (i = 0; environ[i]; i++)
continue;
environ[i] = variable;
}
else if (overwrite)
{
for (i = 0; environ[i]; i++)
{
if (_strstr(environ[i], (char *)name) == environ[i])
{
environ[i] = variable;
}
}
}
return (0);
}


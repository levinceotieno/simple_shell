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
char *var;
int len_name = _strlen((char *)name),
len_value = _strlen((char *)value), i;
var = malloc(sizeof(char) * (len_value + len_name + 2));
if (!var)
{
free(var);
perror("Not enough memory");
return (1);
}
__enter(var, (char *)name, (char *)value, "=");
if (!_getenv((char *)name))
{
for (i = 0; environ[i]; i++)
continue;
environ[i] = var;
}
else if (overwrite)
{
for (i = 0; environ[i]; i++)
{
if (_strstr(environ[i], (char *)name) == environ[i])
{
environ[i] = var;
}
}
}
return (0);
}


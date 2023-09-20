#include "shell.h"

/**
 * get_environ - returns the string array copy of our environ
 * @info: Structure containing potential arguments
 * Return: 0 (Success)
 */
char **get_environ(info_t *info)
{
if (!info->environ || info->env_changed)
{
info->environ = list_to_strings(info->env);
info->env_changed = 0;
}
return (info->environ);
}

/**
 * _unsetenv - remove an environment variable
 * @info: Structure containing potential arguments
 *  Return: 1 on delete, else 0
 * @var: the string env var property
 */
int _unsetenv(info_t *info, char *var)
{
list_t *node = info->env;
size_t i = 0;
char *p;
if (!node || !var)
return (0);
do {
p = beginWth(node->str, var);
if (p && *p == '=')
{
info->env_changed = delete_node_at_index(&(info->env), i);
i = 0;
node = info->env;
continue;
}
node = node->next;
i++;
} while (node);
return (info->env_changed);
}

/**
 * _setenv - Initialize a new environment variable,
 *             or modify an existing one
 * @info: the struct containing potential arguments
 * @var: str env var property
 * @value: str env var value
 *  Return: 0 (Success)
 */
int _setenv(info_t *info, char *var, char *value)
{
char *buffa = NULL;
list_t *node;
char *p;
if (!var || !value)
return (0);
buffa = malloc(_strlen(var) + _strlen(value) + 2);
if (!buffa)
return (1);
_strcpy(buffa, var);
_strcat(buffa, "=");
_strcat(buffa, value);
node = info->env;
do {
p = beginWth(node->str, var);
if (p && *p == '=')
{
free(node->str);
node->str = buffa;
info->env_changed = 1;
return (0);
}
node = node->next;
} while (node);
add_node_end(&(info->env), buffa, 0);
free(buffa);
info->env_changed = 1;
return (0);
}

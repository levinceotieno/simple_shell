#include "shell.h"

/**
 * _myenv - prints the current environment
 * @info: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 * Return: Always 0
 */
int _myenv(info_t *info)
{
print_list_str(info->env);
return (0);
}

/**
 * _getenv - getting the value of an environ variable
 * @info: Structure containing potential arguments
 * @name: env var name
 * Return: the value
 */
char *_getenv(info_t *info, const char *name)
{
list_t *node;
char *p;
for (node = info->env; node; node = node->next)
{
p = starts_with(node->str, name);
if (p && *p)
{
return (p);
}
}
return (NULL);
}

/**
 * _mysetenv - initialize a new environment variable,
 * modify exixting one
 * @info: Structure containing potential arguments
 * Return: Always 0
 */
int _mysetenv(info_t *info)
{
if (info->argc != 3)
{
_eputs("Incorrect number of arguements\n");
return (1);
}
return (_setenv(info, info->argv[1], info->argv[2]) ? 0 : 1);
}

/**
 * _myunsetenv - remove an environment variable
 * @info: Structure containing potential arguments
 * Return: 0 (Success)
 */
int _myunsetenv(info_t *info)
{
int i = 1;
if (info->argc == 1)
{
_eputs("Too few arguements.\n");
return (1);
}
while (i <= info->argc)
{
_unsetenv(info, info->argv[i]);
i++;
}
return (0);
}

/**
 * populate_env_list - pops env linked list
 * @info: Structure containing potential arguments
 * Return: 0(Success)
 */
int populate_env_list(info_t *info)
{
list_t *node = NULL;
size_t i = 0;
while (environ[i])
{
add_node_end(&node, environ[i], 0);
i++;
}
info->env = node;
return (0);
}

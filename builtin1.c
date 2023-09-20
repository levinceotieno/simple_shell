#include "shell.h"
/**
 * _myhistory - displays the history list
 * @info: Structure containing potential arguments
 * Return: 0 (Success)
 */
int _myhistory(info_t *info)
{
print_list(info->history);
return (0);
}

/**
 * unset_alias - sets alias to string
 * @info: parameter struct
 * @str: str alias
 * Return: Always 0 success, 1 on error
 */
int unset_alias(info_t *info, char *str)
{
char *p, c;
int ret;
p = _strchr(str, '=');
c = (p) ? *p : '\0';
*p = 0;
ret = delete_node_at_index(&(info->alias),
get_node_index(info->alias, node_starts_with(info->alias, str, -1)));
*p = c;
return (ret);
}

/**
 * set_alias - sets alias to string
 * @info: parameter struct
 * @str: str alias
 * Return: 0 (success), 1 on error
 */
int set_alias(info_t *info, char *str)
{
char *p;
p = _strchr(str, '=');
if (!p)
return (1);
if (!*++p)
{
return (unset_alias(info, str));
}
else
{
unset_alias(info, str);
}
return (add_node_end(&(info->alias), str, 0) == NULL);
}

/**
 * print_alias - it prints an alias str
 * @node: alias node
 * Return: Always 0 success, 1 on error
 */
int print_alias(list_t *node)
{
char *p = NULL, *a = NULL;
if (!node)
return (1);
p = _strchr(node->str, '=');
if (!p)
return (1);
a = node->str;
while (a <= p)
{
_putchar(*a);
a++;
}
_putchar('\'');
_puts(p + 1);
_puts("'\n");
return (0);
}

/**
 * _myalias - imitate the alias builtin
 * @info: Structure containing potential arguments
 *  Return: 0 (Success)
 */
int _myalias(info_t *info)
{
int i = 0;
char *p = NULL;
list_t *node = NULL;
if (info->argc == 1)
{
node = info->alias;
while (node)
{
print_alias(node);
node = node->next;
}
return (0);
}
i = 1;
while (info->argv[i])
{
p = _strchr(info->argv[i], '=');
if (p)
set_alias(info, info->argv[i]);
else
print_alias(node_starts_with(info->alias, info->argv[i], '='));
i++;
}
return (0);
}

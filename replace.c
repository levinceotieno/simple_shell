#include "shell.h"
/**
 * alternativeAlias - replaces a cmd with its corresponding alias if available.
 * @informat: Pointer to the `inform_t` struct.
 * Return: 1 if an alias is replaced, 0  no alias found.
 */
int alternativeAlias(info_t *info)
{
list_t *node;
char *p;
int a = 0;
while (a < 10)
{
node = node_beginWth(info->alias, info->argv[0], '=');
if (node == NULL)/* If no alias is found */
return (0);
else
{
free(info->argv[0]); /* Free the memory of the old alias */
p = _strchr(node->str, '=');
if (!p)
return (0);
p = _strdup(p + 1);/* Duplicate the content after '=' */
if (!p)
return (0);
info->argv[0] = p;
a++;
}
}
return (1);
}

/**
 * alternativeStr - replaces string
 * @old: address of old string
 * @new: the new str
 * Return: if replaced 1, else 0
 */
int alternativeStr(char **old, char *new)
{
free(*old);
*old = new;
return (1);
}


#include "shell.h"

/**
 * informedEx - initializes info_t struct
 * @info: struct address
 */
void informedEx(info_t *info)
{
info->arg = NULL;
info->argv = NULL;
info->path = NULL;
info->argc = 0;
}

/**
 * set_info - initializes info_t struct
 * @info: struct address
 * @av: argument vector
 */
void set_info(info_t *info, char **av)
{
int i = 0;
info->fname = av[0];
if (info->arg)
{
info->argv = tokstr(info->arg, " \t");
if (!info->argv)
{
info->argv = malloc(sizeof(char *) * 2);
if (info->argv)
{
info->argv[0] = _strdup(info->arg);
info->argv[1] = NULL;
}
}
i = 0;
while (info->argv && info->argv[i])
{
i++;
}
info->argc = i;
replace_alias(info);
replace_vars(info);
}
}

/**
 * free_info - frees info_t struct fields
 * @info: struct address
 * @all: true if freeing all fields
 */
void free_info(info_t *info, int all)
{
_let_free(info->argv);
info->argv = NULL;
info->path = NULL;
if (all)
{
if (!info->cmd_buffa)
free(info->arg);
if (info->env)
free_list(&(info->env));
if (info->history)
free_list(&(info->history));
if (info->alias)
free_list(&(info->alias));
_let_free(info->environ);
info->environ = NULL;
we_free((void **)info->cmd_buffa);
if (info->readfd > 2)
close(info->readfd);
_putchar(FLSHBUFF);
}
}

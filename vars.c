#include "shell.h"
/**
 * alternativeVar - replaces vars in the tokenized string
 * @info: the parameter struct
 * Return: 1 if replaced, 0 otherwise
 */
int alternativeVar(info_t *info)
{
int i = 0;
list_t *node;
for (i = 0; info->argv[i]; i++)
{
if (info->argv[i][0] != '$' || !info->argv[i][1])
continue;
if (!_strcmp(info->argv[i], "$?"))
{
alternativeStr(&(info->argv[i]),
_strdup(convert_number(info->status, 10, 0)));
continue;
}
if (!_strcmp(info->argv[i], "$$"))
{
alternativeStr(&(info->argv[i]),
_strdup(convert_number(getpid(), 10, 0)));
continue;
}
node = node_beginWth(info->env, &info->argv[i][1], '=');
if (node)
{
alternativeStr(&(info->argv[i]),
_strdup(_strchr(node->str, '=') + 1));
continue;
}
alternativeStr(&info->argv[i], _strdup(""));
}
return (0);
}

/**
 * tag_c - checks the current char if is a chain delimiter
 * @info: info struct
 * @buffa: char buffafer
 * @p: address of the current position in buffa
 * Return: 1 chain delimiter, else 0
 */
int tag_c(info_t *info, char *buffa, size_t *p)
{
size_t j = *p;
while (buffa[j] && (buffa[j] == '|' || buffa[j] == '&'))
{
if (buffa[j] == '|')
{
if (buffa[j + 1] == '|')
{
buffa[j] = 0;
j++;
info->buffaferType = CMDOR_;
}
else
return (0); /* Not a valid chain delimiter */
}
else if (buffa[j] == '&')
{
if (buffa[j + 1] == '&')
{
buffa[j] = 0;
j++;
}
else
return (0); /* Not a valid chain delimiter */
}
j++;
}
if (buffa[j] == ';')
{
buffa[j] = 0;
info->buffaferType = CMDCHAINN_;
}
else
return (0); /* Not a valid chain delimiter */
*p = j;
return (1);
}


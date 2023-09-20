#include "shell.h"
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
{
return (0); /* Not a valid chain delimiter */
}
}
else if (buffa[j] == '&')
{
if (buffa[j + 1] == '&')
{
buffa[j] = 0;
j++;
}
else
{
return (0); /* Not a valid chain delimiter */
}
}
j++;
}
if (buffa[j] == ';')
{
buffa[j] = 0;
info->buffaferType = CMDCHAINN_;
}
else
{
return (0); /* Not a valid chain delimiter */
}
*p = j;
return (1);
}


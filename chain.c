#include "shell.h"
/**
 * chaintag - checks we should continue chaining based on last status
 * @info: the parameter struct
 * @buf: the char buffer
 * @p: address of current position in buf
 * @i: starting position in buf
 * @len: length of buf
 * Return: Void
 */
void chaintag(info_t *info, char *buf, size_t *p, size_t i, size_t len)
{
size_t y = *p;
if (info->buffaferType == CMD_AND)
{
if (info->status)
{
buf[i] = 0;
y = len;
}
}
if (info->buffaferType == CMDOR_)
{
if (!info->status)
{
buf[i] = 0;
y = len;
}
}
*p = y;
}


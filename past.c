#include "shell.h"

/**
 * histopast_file - gets the history file
 * @info: parameter struct
 * Return: allocated string containg history file
 */

char *histopast_file(info_t *info)
{
char *buffa, *dir;
dir = _getenv(info, "HOME=");
if (!dir)
return (NULL);
buffa = malloc(sizeof(char) * (_strlen(dir) + _strlen(HIST_FILE) + 2));
if (!buffa)
return (NULL);
buffa[0] = 0;
_strcpy(buffa, dir);
_strcat(buffa, "/");
_strcat(buffa, HIST_FILE);
return (buffa);
}

/**
 * past_write - creates file, or appends to an existing file
 * @info: the parameter struct
 * Return: 1 on success, else -1
 */
int past_write(info_t *info)
{
ssize_t fd;
char *filen = histopast_file(info);
list_t *node = NULL;
if (!filen)
return (-1);
fd = open(filen, O_CREAT | O_TRUNC | O_RDWR, 0644);
free(filen);
if (fd == -1)
return (-1);
for (node = info->history; node; node = node->next)
{
_putsfd(node->str, fd);
_putfd('\n', fd);
}
_putfd(FLSHBUFF, fd);
close(fd);
return (1);
}


#include "shell.h"
/**
 * readH - reads history from file
 * @info: the parameter struct
 * Return: histcount on success, 0 otherwise
 */
int readH(info_t *info)
{
int i, last = 0, count = 0;
ssize_t fd, len, fsize = 0;
struct stat st;
char *buffa = NULL, *filename = histopast_file(info);
if (!filename)
return (0);
fd = open(filename, O_RDONLY);
free(filename);
if (fd == -1)
return (0);
if (!fstat(fd, &st))
fsize = st.st_size;
if (fsize < 2)
return (0);
buffa = malloc(sizeof(char) * (fsize + 1));
if (!buffa)
return (0);
len = read(fd, buffa, fsize);
buffa[fsize] = 0;
if (len <= 0)
return (free(buffa), 0);
close(fd);
for (i = 0; i < fsize; i++)
if (buffa[i] == '\n')
{
buffa[i] = 0;
creatH(info, buffa + last, count++);
last = i + 1;
}
if (last != i)
creatH(info, buffa + last, count++);
free(buffa);
info->histcount = count;
while (info->histcount-- >= MAXHISTOR)
delete_node_at_index(&(info->history), 0);
renumH(info);
return (info->histcount);
}

/**
 * creatH - adds entry to a history linked list
 * @info: Struct contains potential args
 * @buffa: buffafer
 * @linecount: the history linecount, histcount
 * Return:  0 (Success)
 */
int creatH(info_t *info, char *buffa, int linecount)
{
list_t *node = NULL;
if (info->history)
node = info->history;
add_node_end(&node, buffa, linecount);
if (!info->history)
info->history = node;
return (0);
}

/**
 * renumH - re-numbers the history linked list after changes
 * @info: struct containing potential args
 * Return: the new histcount
 */
int renumH(info_t *info)
{
list_t *node = info->history;
int i = 0;
for (; node; node = node->next)
{
node->num = i++;
}
return (info->histcount = i);
}


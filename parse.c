#include "shell.h"

/**
 * is_cmd - checks if a file is an exec cmd
 * @info: the info struct
 * @path: path to the file
 * Return: 1 true, else 0
 */
int is_cmd(info_t *info, char *path)
{
struct stat st;
(void)info;
if (!path || stat(path, &st))
return (0);
if (st.st_mode & S_IFREG)
{
return (1);
}
return (0);
}

/**
 * dupcateChar - dup chars
 * @pathstr: the PATH str
 * @start: start index
 * @stop: stop index
 * Return: ptr 2 new buffafer
 */
char *dupcateChar(char *pathstr, int start, int stop)
{
static char buffa[1024];
int i = 0, j = 0;
for (j = 0, i = start; i < stop; i++)
if (pathstr[i] != ':')
buffa[j++] = pathstr[i];
buffa[j] = 0;
return (buffa);
}

/**
 * fi_ndpath - finds cmd in the path str
 * @info: the info struct
 * @pathstr: the PATH string
 * @cmd: the cmd to find
 * Return: full path of cmd if found or NULL
 */
char *fi_ndpath(info_t *info, char *pathstr, char *cmd)
{
int i = 0, curr_pos = 0;
char *path;
if (!pathstr)
return (NULL);
if ((_strlen(cmd) > 2) && beginWth(cmd, "./"))
{
if (is_cmd(info, cmd))
return (cmd);
}
for (; pathstr[i] != '\0'; i++)
{
if (pathstr[i] == ':')
{
path = dupcateChar(pathstr, curr_pos, i);
if (!*path)
_strcat(path, cmd);
else
{
_strcat(path, "/");
_strcat(path, cmd);
}
if (is_cmd(info, path))
return (path);
if (!pathstr[i])
break;
curr_pos = i + 1;
}
}
path = dupcateChar(pathstr, curr_pos, i);
if (!*path)
_strcat(path, cmd);
else
{
_strcat(path, "/");
_strcat(path, cmd);
}
if (is_cmd(info, path))
return (path);
return (NULL);
}


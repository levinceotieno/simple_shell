#include "shell.h"

/**
 * _which - gets the path of a command
 * @command: a string
 * Return: path to the command
 */

char *_which(char *command)
{
char *path, *path_copy, *path_token, *file_path;
int command_length, dir_length;
struct stat buffer;
path = _getenv("PATH");
if (path)
{
if (stat(command, &buffer) == 0)
{
return (command);
}
path_copy = strdup(path);
command_length = _strlen(command);
path_token = strtok(path_copy, ":");
for (path_token = strtok(path_copy, ":");
path_token != NULL; path_token = strtok(NULL, ":"))
{
dir_length = _strlen(path_token);
file_path = malloc(command_length + dir_length + 2);
join(file_path, path_token, command, "/");
if (stat(file_path, &buffer) == 0)
{
free(path_copy);
return (file_path);
}
else
{
free(file_path);
}
}
free(path_copy);
return (NULL);
}
return (NULL);
}


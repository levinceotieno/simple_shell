#include "shell.h"

/**
 * main - entry point
 * @ac: arg count
 * @av: arg vector
 * Return: 0 (success), 1 error
 */
int main(int ac, char **av)
{
info_t info[] = { INITIALDATA };
int fd = 2;
int new_fd = fd + 3;

if (ac == 2)
{
new_fd = open(av[1], O_RDONLY);
if (new_fd == -1)
{
if (errno == EACCES)
exit(126);
if (errno == ENOENT)
{
_eputs(av[0]);
_eputs(": 0: Can't open this file");
_eputs(av[1]);
_eputchar('\n');
_eputchar(FLSHBUFF);
exit(127);
}
return (EXIT_FAILURE);
}
info->readfd = new_fd;
}
__envList(info);
readH(info);
_ex(info, av);
return (EXIT_SUCCESS);
}


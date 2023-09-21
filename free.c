#include <stdlib.h>

/**
 * twodfre - deallocates the 2D array
 * @grid: grid array ptr
 * Return: void
 */

void twodfre(char **grid)
{
char **grid_cpy = grid;
for (; *grid != NULL; grid++)
{
free(*grid);
}
free(grid_cpy);
}


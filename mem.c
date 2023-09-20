#include "shell.h"

/**
 * we_free - frees a pointer and null adrss
 * @ptr: address of the ptr freed
 * Return: 1 if freed, else 0.
 */
int we_free(void **ptr)
{
if (ptr == NULL || *ptr == NULL)
{
return (0);
}
free(*ptr);
*ptr = NULL;
return (1);
}


#include "shell.h"

/**
 * set_mem - fills memory with a constant byte
 * @s: the pointer to the memory area
 * @b: the byte to fill *s with
 * @n: the amount of bytes to be filled
 * Return: (s) a pointer to the memory area s
 */
char *set_mem(char *s, char b, unsigned int n)
{
unsigned int i = 0;
while (i < n)
{
s[i] = b;
i++;
}
return (s);
}

/**
 * _let_free - frees a string of strings
 * @pp: str of strs
 * Return: void
 */
void _let_free(char **pp)
{
char **a = pp;
if (!pp)
return;
for (; *pp; pp++)
{
free(*pp);
}
free(a);
}

/**
 * __rrealloC - reallocates a block of memory
 * @ptr: pointer to previous malloc'ated block
 * @old_size: byte size of previous block
 * @new_size: byte size of new block
 * Return: pointer to da ol'block nameen.
 */
void *__rrealloC(void *ptr, unsigned int old_size, unsigned int new_size)
{
char *p;
if (!ptr)
return (malloc(new_size));
else if (!new_size)
{
free(ptr);
return (NULL);
}
else if (new_size == old_size)
return (ptr);
p = malloc(new_size);
if (!p)
return (NULL);
old_size = old_size < new_size ? old_size : new_size;
while (old_size--)
p[old_size] = ((char *)ptr)[old_size];
free(ptr);
return (p);
}


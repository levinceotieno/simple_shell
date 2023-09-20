#include "shell.h"

/**
 * _strcpy - copying str
 * @dest: destination
 * @src: source
 * Return: ptr 2 dest
 */
char *_strcpy(char *dest, char *src)
{
int i = 0;
if (dest == src || src == 0)
return (dest);
for (i = 0; src[i]; i++)
dest[i] = src[i];
dest[i] = 0;
return (dest);
}

/**
 * _strdup - duplicates str
 * @str: str 2 duplicate
 * Return: ptr 2 duplicated str
 */
char *_strdup(const char *str)
{
int length = 0;
char *ret;
if (str == NULL)
return (NULL);
while (*str++)
length++;
ret = malloc(sizeof(char) * (length + 1));
if (!ret)
return (NULL);
for (length++; length--;)
ret[length] = *--str;
return (ret);
}

/**
 * _puts - prints the input string
 * @str: string
 * Return: void
 */
void _puts(char *str)
{
int i;
if (!str)
return;
for (i = 0; str[i] != '\0'; i++)
{
_putchar(str[i]);
}
}

/**
 * _putchar - prints the character c to stdout
 * @c: character
 * Return: 1 (Success)
 */
int _putchar(char c)
{
static int i;
static char buffa[PRINTBUFF_SIZE];
if (c == (char)BUF_FLUSH || i >= PRINTBUFF_SIZE)
{
write(1, buffa, i);
i = 0;
}
if (c != (char)BUF_FLUSH)
buffa[i++] = c;
return (1);
}


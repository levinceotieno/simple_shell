#include "shell.h"

/**
 * _eputs - prints an input string
 * @str: the string to be printed
 * Return: Nothing
 */
void _eputs(char *str)
{
int i;
if (!str)
return;
for (i = 0; str[i] != '\0'; i++)
{
_eputchar(str[i]);
}
}

/**
 * _eputchar - writes the character c to stderr
 * @c: The character to print
 * Return: On success 1.
 */
int _eputchar(char c)
{
static int i;
static char buffa[PRINTBUFF_SIZE];
do {
if (c == (char)BUF_FLUSH || i >= PRINTBUFF_SIZE)
{
write(2, buffa, i);
i = 0;
}
if (c != (char)BUF_FLUSH)
buffa[i++] = c;
} while (0);
return (1);
}

/**
 * _putfd - it writes the character c to given fd
 * @c: char to print
 * @fd: filedescriptor to write to
 * Return: On success 1.
 */
int _putfd(char c, int fd)
{
static int i;
static char buffa[PRINTBUFF_SIZE];
do {
if (c == (char)BUF_FLUSH || i >= PRINTBUFF_SIZE)
{
write(fd, buffa, i);
i = 0;
}
if (c != (char)BUF_FLUSH)
buffa[i++] = c;
} while (0);
return (1);
}

/**
 * _putsfd - prints an input string
 * @str: the string to be printed
 * @fd: filedescriptor to write to
 * Return: numb of chars put
 */
int _putsfd(char *str, int fd)
{
int i, count = 0;
if (!str)
return (0);
for (i = 0; str[i] != '\0'; i++)
{
count += _putfd(str[i], fd);
}
return (count);
}

#include "shell.h"

/**
 * _eputs - prints an input string
 * @str: the string to be printed
 * Return: Nothing
 */
void _eputs(char *str)
{
if (!str)
return;
for (int i = 0; str[i] != '\0'; i++)
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
static char buf[WRITE_BUF_SIZE];
do {
if (c == (char)BUF_FLUSH || i >= WRITE_BUF_SIZE)
{
write(2, buf, i);
i = 0;
}
if (c != (char)BUF_FLUSH)
buf[i++] = c;
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
static char buf[WRITE_BUF_SIZE];
do {
if (c == (char)BUF_FLUSH || i >= WRITE_BUF_SIZE)
{
write(fd, buf, i);
i = 0;
}
if (c != (char)BUF_FLUSH)
buf[i++] = c;
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
int count = 0;
if (!str)
return (0);
for (int i = 0; str[i] != '\0'; i++)
{
count += _putfd(str[i], fd);
}
return (count);
}

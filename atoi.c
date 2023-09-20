#include "shell.h"

/**
 * active - returns true if shell is interactive mode
 * @info: struct address
 *
 * Return: 1 if interactive mode, 0 otherwise
 */
int active(info_t *info)
{
return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 * _isdelim - checks if character is a delimeter
 * @c: char checked
 * @delim: delimeter str
 * Return: 1 true, 0 false
 */
int _isdelim(char c, char *delim)
{
for (; *delim; delim++)
{
if (*delim == c)
{
return (1);
}
}
return (0);
}

/**
 * is_alpha - it checks for alphabetic character
 * @c: char inputed
 * Return: 1 if c is alphabetic, 0 otherwise
 */

int is_alpha(int c)
{
while (1)
{
if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
return (1);
else
return (0);
}
}

/**
 * __atoi_ - it converts a string to an integer
 * @s: string to be converted
 * Return: 0 if no num, converted number if otherwise
 */

int __atoi_(char *s)
{
int i, sign = 1, flag = 0, output;
unsigned int result = 0;

do {
if (s[i] == '-')
sign *= -1;
if (s[i] >= '0' && s[i] <= '9')
{
flag = 1;
result *= 10;
result += (s[i] - '0');
}
else if (flag == 1)
{
flag = 2;
}
i++;
}
while (s[i - 1] != '\0' && flag != 2);
if (sign == -1)
output = -result;
else
output = result;
return output;
}

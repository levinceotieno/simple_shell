#include "shell.h"

/**
 * _erratoi - converts a string to an integer
 * @s: string to be converted
 * Return: 0 if no numbs in the string,
 * converted number otherwise -1 on error
 */
int _erratoi(char *s)
{
int i = 0;
unsigned long int result = 0;
if (*s == '+')
s++;
do {
if (s[i] >= '0' && s[i] <= '9')
{
result *= 10;
result += (s[i] - '0');
if (result > INT_MAX)
return (-1);
}
else
{
return (-1);
}
i++;
} while (s[i] != '\0');
return (result);
}

/**
 * print_error - printing an error message
 * @info: the parameter & return info struct
 * @estr: string containing specified error type
 * Return: 0 if no numbers in string,
 * converted number else -1 on error
 */
void print_error(info_t *info, char *estr)
{
_eputs(info->fname);
_eputs(": ");
print_d(info->line_count, STDERR_FILENO);
_eputs(": ");
_eputs(info->argv[0]);
_eputs(": ");
_eputs(estr);
}

/**
 * print_d - function prints a decimal (integer) number (base 10)
 * @input: input
 * @fd: filedescriptor to write to
 * Return: numb of chars printed
 */
int print_d(int input, int fd)
{
int (*__putchar)(char) = _putchar;
int i, count = 0;
unsigned int _abs_, current;
if (fd == STDERR_FILENO)
__putchar = _eputchar;
if (input < 0)
{
_abs_ = -input;
__putchar('-');
count++;
}
else
_abs_ = input;
current = _abs_;
for (i = 1000000000; i > 1; i /= 10)
{
if (_abs_ / i)
{
__putchar('0' + current / i);
count++;
}
current %= i;
}
__putchar('0' + current);
count++;
return (count);
}

/**
 * convert_number - converter function, a clone of itoa
 * @num: number
 * @base: base
 * @flags: argument flags
 * Return: string
 */
char *convert_number(long int num, int base, int flags)
{
static char buffafer[50];
char sign = 0;
char *ptr, *array;
unsigned long n = num;
if (!(flags & UNSIGNED__) && num < 0)
{
n = -num;
sign = '-';
}
array = (flags & LOWERCASE_) ? "0123456789abcdef" : "0123456789ABCDEF";
ptr = &buffafer[49];
*ptr = '\0';
while (n != 0)
{
*--ptr = array[n % base];
n /= base;
}
if (sign)
*--ptr = sign;
return (ptr);
}

/**
 * remove_comments - function replaces first instance of '#' with '\0'
 * @buffa: address of the string to modify
 *
 * Return: Always 0;
 */
void remove_comments(char *buffa)
{
int i;

for (i = 0; buffa[i] != '\0'; i++)
if (buffa[i] == '#' && (!i || buffa[i - 1] == ' '))
{
buffa[i] = '\0';
break;
}
}

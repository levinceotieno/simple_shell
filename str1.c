#include "shell.h"
/**
 * _strspn - strspn
 * @s: string being checked
 * @accept : reference string
 * Return: length of char of `accept` contained in `s`
 */
unsigned int _strspn(char *s, char *accept)
{
int i;
int j;
int c = 0;
int accept_chars[256] = {0};

for (j = 0; accept[j] != '\0'; j++)
{
accept_chars[(unsigned char)accept[j]] = 1;
}
for (i = 0; s[i] != '\0'; i++)
{
if (accept_chars[(unsigned char)s[i]])
c++;
else
break;
}
return (c);
}

/**
 * _atoi - converts a string to an int
 * @str: the string to convert
 * Return: converted string
 */

int _atoi(char *str)
{
int i = 0, sign = 1, flag = 0;
int result = 0;

for (i = 0; str[i] != '\0' && flag != -1; i++)
{
if (str[i] == '-')
sign *= -1;
if (_isdigit(str[i]))
{
flag = 1;
result *= 10;
result += (str[i] - '0');
}
else if (flag == 1)
flag = -1;
}
if (sign == -1)
return (-1 * result);
return (result);
}

/**
 * _strstr - locates the first matching substring of accept in str
 * @haystack: string to be searched
 * @needle: refrence string
 * Return: ptr to the 1st char of the matched str
 */

char *_strstr(char *haystack, char *needle)
{
if (haystack == NULL || *needle == '\0')
return (haystack);
while (*haystack != 0)
{
if ((*haystack == *needle) && *(haystack + 1) == *(needle + 1))
return (haystack);
haystack++;
}
return (((void *) 0));
}

/**
 * __enter - __enters two strings, a delimiter and a null byte
 * @str1: lead string
 * @str2: trailing string
 * @delim: delimiter
 * @store: destination
 */
void __enter(char *store, char *str1, char *str2, const char *delim)
{
_strcpy(store, str1);
_strcat(store, (char *)delim);
_strcat(store, str2);
_strcat(store, "\0");
}


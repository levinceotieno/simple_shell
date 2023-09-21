#include "shell.h"
/**
 * _strlen - prints the number of characters of a string
 * @s: string
 * Return: length of s
 */
int _strlen(char *s)
{
int len = 0;

for (; *s != '\0'; s++)
{
len++;
}
return (len);
}
/**
 * _strcpy - copies a string to another string
 * @dest: destination of copied string
 * @src: string to be copied
 * Return: pointer to dest
 */

char *_strcpy(char *dest, char *src)
{
	char *r_dest = dest;

	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
	return (r_dest);
}
/**
 * _strcmp - Compares two strings
 * @s1: first string
 * @s2: second string
 * Return: string difference
 */

int _strcmp(char *s1, char *s2)
{
char *y_s1 = s1;
char *y_s2 = s2;
for (; *y_s1 != '\0' && *y_s2 != '\0'; y_s1++, y_s2++)
{
if (*y_s1 != *y_s2)
{
return (*y_s1 - *y_s2);
}
}
if (*s1 == '\0' || *s2 == '\0')
return (0);
return (*y_s1 - *y_s2);
}

/**
 * _strcat - concatenates two strings
 * @src: source to be appended
 * @dest : destination string.
 * Return: pointer to first element to dest.
 */

char *_strcat(char *dest, char *src)
{
char *p_dest = dest;
for (; *dest != '\0'; dest++)
{
}
for (; *src != '\0'; dest++, src++)
{
*dest = *src;
}
*dest = '\0';
return (p_dest);/* returns address of the resulting string */
}

/**
 * _strdup - returns pointer to a copy of str
 * @str: string to be copied
 * Return: pointer to copy
 */

char *_strdup(char *str)
{
unsigned int l_str = 0;
char *copy;
unsigned int i = 0;

if (str == NULL)
return (NULL);
l_str = _strlen(str);
copy = (char *)malloc((sizeof(char) * (l_str + 1)));
if (copy == NULL)
return (NULL);
while (1)
{
if (i == l_str + 1)
{
copy[i] = '\0';
break;
}
copy[i] = *(str + i);
i++;
}
return (copy);
}


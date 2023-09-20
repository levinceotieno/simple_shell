#include "shell.h"

/**
 * _strlen - returns the length of a string
 * @s: the str being checked length
 * Return: len of string
 */
int _strlen(char *s)
{
int i;
if (!s)
return (0);
for (i = 0; s[i] != '\0'; i++)
{
}
return (i);
}

/**
 * _strcmp - performs lexicogarphic comparison of two strangs.
 * @s1: the first strang
 * @s2: the second strang
 *
 * Return: negative if s1 < s2, positive if s1 > s2, zero if s1 == s2
 */
int _strcmp(char *s1, char *s2)
{
for (; *s1 && *s2; s1++, s2++)
{
if (*s1 != *s2)
return (*s1 - *s2);
}
if (*s1 == *s2)
return (0);
else
return (*s1 < *s2 ? -1 : 1);
}

/**
 * beginWth - checks if needle starts with haystack
 * @haystack: string to search
 * @needle: sub_string 2 find
 * Return: address of next char
 */
char *beginWth(const char *haystack, const char *needle)
{
for (; *needle; needle++, haystack++)
{
if (*needle++ != *haystack++)
return (NULL);
}
return ((char *)haystack);
}

/**
 * _strcat - concat 2 strs
 * @dest: destination buffafer
 * @src: source buffafer
 * Return: ptr 2 dest buffafer
 */
char *_strcat(char *dest, char *src)
{
char *j = dest;
while (*dest)
dest++;
while (*src)
*dest++ = *src++;
*dest = *src;
return (j);
}


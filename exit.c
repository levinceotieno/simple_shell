#include "shell.h"

/**
 **_strncpy - copy a string
 *@dest: destination
 *@src: source
 *@n: amount of chars copied
 *Return: the concatenated string
 */
char *_strncpy(char *dest, char *src, int n)
{
int i = 0;
while (i < n - 1 && src[i] != '\0')
{
dest[i] = src[i];
i++;
}
while (i < n)
{
dest[i] = '\0';
i++;
}
return (dest);
}

/**
 **_strncat - it concatenates 2 strings
 *@dest: string1
 *@src: string2
 *@n: amount of bytes
 *Return: concatinates string
 */
char *_strncat(char *dest, char *src, int n)
{
int i, j;
char *s = dest;
for (i = 0; dest[i] != '\0'; i++)
{
}
j = 0;
while (src[j] != '\0' && j < n)
{
dest[i] = src[j];
i++;
j++;
}
if (j < n)
{
dest[i] = '\0';
}
return (s);
}

/**
 **_strchr - it locates a character in the string
 *@s: string
 *@c: character
 *Return: (s) is pointr to memory
 */
char *_strchr(char *s, char c)
{
while (*s != '\0')
{
if (*s == c)
{
return (s);
}
s++;
}
return (NULL);
}

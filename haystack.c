#include "shell.h"
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


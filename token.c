#include "shell.h"

/**
 * **tokstr - it split a str to words
 * @str: input str
 * @d: delimeter str
 * Return: ptr 2 an array of strs
 */
char **tokstr(char *str, char *d)
{
int i = 0, j = 0, k = 0, m = 0, numWtn = 0;
char **s;
if (str == NULL || str[0] == 0)
return (NULL);
if (!d)
d = " ";
while (str[i] != '\0')
{
if (!_isdelim(str[i], d) && (_isdelim(str[i + 1], d) || !str[i + 1]))
numWtn++;
i++;
}
if (!_isdelim(str[i], d) && (_isdelim(str[i + 1], d) || !str[i + 1]))
numWtn++;
if (numWtn == 0)
return (NULL);
s = malloc((1 + numWtn) * sizeof(char *));
if (!s)
return (NULL);
for (i = 0, j = 0; j < numWtn; j++)
{
while (_isdelim(str[i], d))
i++;
k = 0;
for (k = 0; !_isdelim(str[i + k], d) && str[i + k]; k++)
;
s[j] = malloc((k + 1) * sizeof(char));
if (!s[j])
{
for (k = 0; k < j; k++)
free(s[k]);
free(s);
return (NULL);
}
for (m = 0; m < k; m++)
s[j][m] = str[i++];
s[j][m] = 0;
}
s[j] = NULL;
return (s);
}

/**
 * **tokstr2 - splitting string into words
 * @str: input str
 * @d: delimeter
 * Return: ptr 2 an array of strs
 */
char **tokstr2(char *str, char d)
{
int i, j, k, m, numWtn = 0;
char **s;
if (str == NULL || str[0] == 0)
return (NULL);
for (i = 0; str[i] != '\0'; i++)
{
if ((str[i] != d && str[i + 1] == d) ||
(str[i] != d && !str[i + 1]) || str[i + 1] == d)
numWtn++;
}
if (numWtn == 0)
return (NULL);
s = malloc((1 + numWtn) * sizeof(char *));
if (!s)
return (NULL);
for (i = 0, j = 0; j < numWtn; j++)
{
while (str[i] == d && str[i] != d)
i++;
for (k = 0; str[i + k] != d && str[i + k] &&
str[i + k] != d; k++)
;
s[j] = malloc((k + 1) * sizeof(char));
if (!s[j])
{
for (k = 0; k < j; k++)
free(s[k]);
free(s);
return (NULL);
}
m = 0;
while (m < k)
{
s[j][m] = str[i++];
m++;
}
s[j][m] = 0;
}
s[j] = NULL;
return (s);
}


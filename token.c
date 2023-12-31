#include "shell.h"
/**
 * tokenize - the funct tokenize chars
 * @str: string to tokenize
 * @delim: delimiter
 * Return: array to tokens
 */
char **tokenize(char *str, const char *delim)
{
char **words, *cpy, *token;
int i = 0, num_tokens = 0;
if (str == NULL || *str == '\0')
return (NULL);
cpy = malloc(sizeof(char) * strlen(str) + 1);
if (cpy == NULL)
return (NULL);
strcpy(cpy, str);
token = strtok(str, delim);

do {
if (token[0] == '#')
break;
num_tokens++;
token = strtok(NULL, delim);
} while (token != NULL);
num_tokens++;
words = malloc(sizeof(char *) * num_tokens);
if (words == NULL)
return (NULL);
token = strtok(cpy, delim);
for (i = 0; i < num_tokens - 1; i++)
{
if (token[0] == '#')
break;
words[i] = malloc(sizeof(char) * strlen(token) + 1);
strcpy(words[i], token);
token = strtok(NULL, delim);
}
words[i] = NULL;
free(cpy);
return (words);
}


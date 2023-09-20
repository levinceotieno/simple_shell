#include "shell.h"

/**
 * input_buffa - buffafers chained commands
 * @info: parameter struct
 * @buffa: address of buffafer
 * @len: address of len
 * Return: read bytes
 */
ssize_t input_buffa(info_t *info, char **buffa, size_t *len)
{
ssize_t r = 0;
size_t len_p = 0;
if (!*len)
{
/*we_free((void **)info->cmd_buffa);*/
_let_free(buffa);
*buffa = NULL;
signal(SIGINT, sigintHandler);

#if GET_LINE
r = getline(buffa, &len_p, stdin);
#else
r = _getline(info, buffa, &len_p);
#endif
if (r > 0)
{
if ((*buffa)[r - 1] == '\n')
{
(*buffa)[r - 1] = '\0';
r--;
}
info->linecount_flag = 1;
remove_comments(*buffa);
creatH(info, *buffa, info->histcount++);
/* if (_strchr(*buffa, ';')) is this a command chain? */
*len = r;
info->cmd_buffa = buffa;
}
}
return (r);
}

/**
 * get_input - gets a line minus the newline
 * @info: parameter struct
 * Return: bytes read
 */
ssize_t get_input(info_t *info)
{
static char *buffa;
static size_t i, j, len;
ssize_t r = 0;
char **buffa_p = &(info->arg), *p;
_putchar(FLSHBUFF);
r = input_buffa(info, &buffa, &len);
if (r == -1) /* EOF */
return (-1);
if (len)
{
j = i;
p = buffa + i; /* get pointer for return */
check_chain(info, buffa, &j, i, len);
while (j < len)
{
if (tag_c(info, buffa, &j))
break;
j++;
}

i = j + 1; /* increment past nulled ';'' */
if (i >= len)
{
i = len = 0; /* reset position and length */
info->buffaferType = CMD_NORM;
}
*buffa_p = p; /* pass back pointer to current command position */
return (_strlen(p));
}
*buffa_p = buffa;
return (r);
}

/**
 * read_buffa - reads a buffafer
 * @info: parameter struct
 * @buffa: buffafer
 * @i: size
 * Return: r
 */
ssize_t read_buffa(info_t *info, char *buffa, size_t *i)
{
ssize_t r = 0;
if (*i)
return (0);
r = read(info->readfd, buffa, READ_BUF_SIZE);
if (r >= 0)
*i = (size_t)r;
return (r);
}

/**
 * _getline - gets the next line of input from STDIN
 * @info: parameter struct
 * @ptr: address of pointer to buffafer, preallocated or NULL
 * @length: size of preallocated ptr buffafer if not NULL
 *
 * Return: s
 */
int _getline(info_t *info, char **ptr, size_t *length)
{
static char buffa[READ_BUF_SIZE];
static size_t i, len;
size_t k;
ssize_t r = 0, s = 0;
char *p = NULL, *new_p = NULL, *c;
p = *ptr;
if (p && length)
s = *length;
if (i == len)
i = len = 0;
r = read_buffa(info, buffa, &len);
if (r == -1 || (r == 0 && len == 0))
return (-1);
c = _strchr(buffa + i, '\n');
k = c ? 1 + (unsigned int)(c - buffa) : len;
new_p = __rrealloC(p, s, s ? s + k : k + 1);
if (!new_p)
return (p ? free(p), -1 : -1);
if (s)
_strncat(new_p, buffa + i, k - i);
else
_strncpy(new_p, buffa + i, k - i + 1);

s += k - i;
i = k;
p = new_p;
if (length)
*length = s;
*ptr = p;
return (s);
}

/**
 * sigintHandler - blocks ctrl-C
 * @sig_num: the signal number
 * Return: void
 */
void sigintHandler(__attribute__((unused))int sig_num)
{
_puts("\n");
_puts("$ ");
_putchar(FLSHBUFF);
}

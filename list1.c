#include "shell.h"

/**
 * list_len - determines length of linked list
 * @h: ptr to 1st node
 * Return: size of the list
 */
size_t list_len(const list_t *h)
{
size_t i;
for (i = 0; h; i++)
{
h = h->next;
}
return (i);
}

/**
 * list_to_strings - returns an array of strings of the list->str
 * @head: ptr to 1st node
 * Return: array of strs
 */
char **list_to_strings(list_t *head)
{
list_t *node = head;
size_t i = list_len(head), j;
char **strs;
char *str;
if (!head || !i)
return (NULL);
strs = malloc(sizeof(char *) * (i + 1));
if (!strs)
return (NULL);

i = 0;
while (node)
{
str = malloc(_strlen(node->str) + 1);
if (!str)
{
for (j = 0; j < i; j++)
free(strs[j]);
free(strs);
return (NULL);
}
str = _strcpy(str, node->str);
strs[i] = str;
node = node->next;
i++;
}
strs[i] = NULL;
return (strs);
}

/**
 * print_list - Printing all elements of a list_t linked list
 * @h: ptr to 1st node
 * Return: size of list
 */
size_t print_list(const list_t *h)
{
size_t i = 0;
for (; h; h = h->next, i++)
{
_puts(convert_number(h->num, 10, 0));
_putchar(':');
_putchar(' ');
_puts(h->str ? h->str : "(nil)");
_puts("\n");
}
return (i);
}

/**
 * node_starts_with - returns node whose string starts with prefix
 * @node: ptr to list head
 * @prefix: str to match
 * @c: nxt char after prefix to match
 * Return: match node or null
 */
list_t *node_starts_with(list_t *node, char *prefix, char c)
{
char *p = NULL;
for (; node; node = node->next)
{
p = starts_with(node->str, prefix);
if (p && ((c == (char)-1) || (*p == c)))
return (node);
}
return (NULL);
}

/**
 * get_node_index - gets the index of a node
 * @head: ptr to list head
 * @node: ptr to the node
 * Return: index of node or -1
 */
ssize_t get_node_index(list_t *head, list_t *node)
{
size_t i = 0;
for (; head; head = head->next, i++)
{
if (head == node)
return (i);
}
return (-1);
}

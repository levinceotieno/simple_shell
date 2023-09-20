#include "shell.h"
/**
 * node_beginWth - returns node whose string starts with prefix
 * @node: ptr to list head
 * @prefix: str to match
 * @c: nxt char after prefix to match
 * Return: match node or null
 */
list_t *node_beginWth(list_t *node, char *prefix, char c)
{
char *p = NULL;
for (; node; node = node->next)
{
p = beginWth(node->str, prefix);
if (p && ((c == (char)-1) || (*p == c)))
return (node);
}
return (NULL);
}

/**
 * nodeIndex - gets the index of a node
 * @head: ptr to list head
 * @node: ptr to the node
 * Return: index of node or -1
 */
ssize_t nodeIndex(list_t *head, list_t *node)
{
size_t i = 0;
for (; head; head = head->next, i++)
{
if (head == node)
return (i);
}
return (-1);
}


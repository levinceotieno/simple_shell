#include "shell.h"

/**
 * remov_nodeAtIndex - deletes node at given index
 * @head: address of ptr to 1st node
 * @index: index of node to delete
 * Return: 1 success, 0 failure
 */
int remov_nodeAtIndex(list_t **head, unsigned int index)
{
list_t *node, *prev_node;
unsigned int i;
if (!head || !*head)
return (0);
if (index == 0)
{
node = *head;
*head = (*head)->next;
free(node->str);
free(node);
return (1);
}

prev_node = *head;
for (i = 0, node = *head; node; i++, node = node->next)
{
if (i == index)
{
prev_node->next = node->next;
free(node->str);
free(node);
return (1);
}
}
return (0);
}

/**
 * free_list - free all nodesof list
 * @head_ptr: addrrs of pointer to head node
 * Return: void
 */
void free_list(list_t **head_ptr)
{
list_t *node, *next_node, *head;
if (!head_ptr || !*head_ptr)
return;
head = *head_ptr;
node = head;
for (node = head; node; node = next_node)
{
next_node = node->next;
free(node->str);
free(node);
}
*head_ptr = NULL;
}


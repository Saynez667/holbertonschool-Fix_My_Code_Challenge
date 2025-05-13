#include "lists.h"
#include <stdlib.h>

/**
 * delete_dnodeint_at_index - Delete a node at a specific index from a list
 *
 * @head: A pointer to the pointer to the first element of a list
 * @index: The index of the node to delete
 *
 * Return: 1 on success, -1 on failure
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
    dlistint_t *current;
    unsigned int p;

    if (!head || !*head)
        return (-1);

    current = *head;
    p = 0;

    /* Traverse to the node at index */
    while (current && p < index)
    {
        current = current->next;
        p++;
    }

    if (!current)
        return (-1);

    /* If node to delete is the head */
    if (current == *head)
    {
        *head = current->next;
        if (*head)
            (*head)->prev = NULL;
    }
    else
    {
        if (current->prev)
            current->prev->next = current->next;
        if (current->next)
            current->next->prev = current->prev;
    }

    free(current);
    return (1);
}

#include <stdlib.h>
#include "lists.h"

/**
 * insert_node: This function found the corret position for insert in the list
 * @head: Head of the list
 * @number: The number that add in the list.
 * Return: the addres of the nre number.
 */
listint_t *insert_node(listint_t **head, int number)
{
    listint_t **new = head;
    listint_t *current = malloc(sizeof(listint_t));

    if (current == NULL)
        return (NULL);

    while (*new && (*new)->n < number)
		new = &(*new)->next;

    current->n = number;
    current->next = *new;

    *new = current;
    return (current);
}

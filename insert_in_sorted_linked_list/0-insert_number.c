#include <stdlib.h>
#include "linked_lists.h"

/**
 *insert_node: This function found the corret position for insert in the list
 *@head: Head of the list
 *@number: Th enumber that add in the list
 */
listint_t *insert_node(listint_t **head, int number)
{
    listint_t *new;
    listint_t *current;
    listint_t *temp;
    new = *head;

    current = malloc(sizeof(listint_t));
    temp = malloc(sizeof(listint_t));
    new = malloc(sizeof(listint_t));

    if (new == NULL)
        return (NULL);

    while (number < new->n) {
        new = new->next;
        if (number > new->n)
            current = new;
            temp = number;
            current->next = temp->next;
            temp->next = new->next;          
    }
}
|
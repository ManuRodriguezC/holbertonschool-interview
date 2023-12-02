#include "search.h"

/**
 * linear_skip - Found value and index in the list
 *
 * @list: Pointer to the head node of the list
 * @value: Value to need found in the list
 * Return: Return the posiiton likend with the value
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
    if (list == NULL)
        return NULL;

    skiplist_t *current = list;
    skiplist_t *next = list->express;

    while (next != NULL)
    {
        printf("Value checked at index [%lu] = [%d]\n", next->index, next->n);
        if (value <= next->n)
        {
            printf("Value found between indexes [%lu] and [%lu]\n", current->index, next->index);
            while (current != NULL)
            {
                if (current->n == value)
                {
                    printf("Value checked at index [%lu] = [%d]\n", current->index, current->n);
                    return current;
                }
                printf("Value checked at index [%lu] = [%d]\n", current->index, current->n);
                current = current->next;
            }
        }
        current = next;
        if (next->express != NULL)
            next = next->express;
        else {
            next = next->next->next;
        }
    }
return NULL;
}


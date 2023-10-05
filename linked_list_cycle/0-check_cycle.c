#include <stdio.h>
#include "lists.h"


/**
* check_cycle - Check if the list is cycle.
* @list: List that check if id cycle
* Return: 0 if is cycle and 1 if not is cycle
*/
int check_cycle(listint_t *list)
{
    listint_t *slow = list;
    listint_t *fast = list;

    if (list == NULL || list->next == NULL)
    {
        return 0;
    }

    while (slow && fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
        {
            return 1;
        }
    }
    return 0;
}
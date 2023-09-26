#include <stdio.h>
#include "lists.h"

/**
* is_palindrome: This function reveiced if linked list is palindrome
* @head: The head of the linked lists
* Return: if is palindrome return true and if not is return false
*/
int is_palindrome(listint_t **head)
{
    if (*head == NULL)
        return 1;

    listint_t *slow = *head;
    listint_t *fast = *head;
    listint_t *prev = NULL;

    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        listint_t *next = slow->next;
        slow->next = prev;
        slow = next;
    }

    if (fast != NULL)
        slow = slow->next;

    while (prev != NULL && slow !=NULL)
    {
        if (prev->n != slow->n)
            return 0;
        prev = prev->next;
        slow = slow->next;
    }

    return 1;
}
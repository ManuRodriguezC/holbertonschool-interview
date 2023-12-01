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
   skiplist_t *found;
   skiplist_t *next = list->express;

   while (current != NULL)
   {
       printf("Value checked at index [%lu] = [%d]\n", next->index, next->n);
       if (next->n > value)
       {
           printf("Value found between indexes [%lu] and [%lu]\n", current->index, next->index);
           found = current;
           while (found != NULL)
           {
               printf("Value checked at index [%lu] = [%d]\n", found->index, found->n);
               if (value == found->n)
               {
                    printf("Found %d at index: %lu", found->n, found->index);
                    return NULL;
               }
               found = found->next;
               return found;
           }
       }
       current = next;
       if (next != NULL)
           next = next->express;
   }

   return NULL;
}

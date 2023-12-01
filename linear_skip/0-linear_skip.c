#include "search.h"


skiplist_t *linear_skip(skiplist_t *list, int value)
{
   if (list == NULL)
       return NULL;

   skiplist_t *current = list;
   skiplist_t *next = list->express;

   while (current != NULL)
   {
       printf("Value checked at index [%lu] = [%d]\n", current->index, current->n);
       if (current->n == value)
       {
           printf("Value found between indexes [%lu] and [%lu]\n", current->index, next->index);
           return current;
       }
       current = next;
       if (next != NULL)
           next = next->express;
   }

   return NULL;
}

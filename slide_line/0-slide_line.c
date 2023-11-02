#include <stdlib.h>
#include <stdio.h>
#include "slide_line.h"

/**
* slide_line - Function simulate 2048 GAME
* @line: Is the list that run and create the new list.
* @size: The size of the list.
* @direction: The direction of the list, this will to be right or left.
* Return: 1 if is succsessfull or 0 is failed.
*/
int slide_line(int *line, size_t size, int direction)
{
   int i, pos, temp, s = size;

   if (direction != SLIDE_LEFT && direction != SLIDE_RIGHT)
       return 0;

   if (direction == SLIDE_LEFT)
   {
       for (i = 0; i < s; i++)
       {
            if (line[i] != 0 && line[i] == line[i + 1])
            {
                line[i] *= 2;
                line[i + 1] = 0;
                for (pos = i + 1; pos < s; pos++)
                {
                    temp = line[pos];
                    line[pos] = line[pos + 1];
                    line[pos + 1] = line[pos];
                }
            }
       }
   }
   else
   {
        for (i = s; i > 0; i--)
        {
            if (line[i] != 0 && line[i] == line[i - 1])
            {
                line[i] *= 2;
                line[i - 1] = 0;
                for (pos = i - 1; pos > 0; pos--)
                {
                    temp = line[pos];
                    line[pos] = line[pos - 1];
                    line[pos - 1] = temp;
                }
            }
        }
   }
   return 1;
}

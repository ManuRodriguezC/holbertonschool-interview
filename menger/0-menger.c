#include "menger.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/**
 * print_menger - Print the elements for a created Menger sponge
 * @posx: Position of the element on the x-axis
 * @posy: Position of the element on the y-axis
 * @col: Column number of the element
 * @row: Row number of the element
 * @c1: Column number of the first sub-element
 * @r1: Row number of the first sub-element
 * @c2: Column number of the second sub-element
 * @r2: Row number of the second sub-element
 * @c3: Column number of the third sub-element
 * @r3: Row number of the third sub-element
 * @c4: Column number of the fourth sub-element
 * @r4: Row number of the fourth sub-element
 *
 * Description: This function checks if the position of
 * the element equals 2 in either x or y axis,
 * or if the position of any sub-element equals 2.
 * If it does, it prints a space.
 * Otherwise, it prints a '#'. This is done to create
 * the pattern of a Menger sponge.
 */
void print_menger(int posx, int posy, int col, int row, int c1,
int r1, int r2, int c2, int r3, int c3, int r4, int c4)
{
if ((posx == 2 && posy == 2) ||
(col == 2 && row == 2) ||
(c1 == 2 && r1 == 2) ||
(c2 == 2 && r2 == 2) ||
(c3 == 2 && r3 == 2) ||
(c4 == 2 && r4 == 2))
{
printf(" ");
}
else
{
printf("#");
}
}

/**
 * set_values - Set a new value to a variable
 * @value: A pointer to the variable that we want to change
 * @new_value: The new value that we want to assign to the variable
 *
 * Description: This function takes a pointer to an
 * int variable and an int value.
 * It changes the value of the variable pointed to
 * by the pointer to the new value.
 */
void set_values(int *value, int new_value)
{
*value = new_value;
}

/**
 * update_values - This function compares the first variable with a
 * given number. If they are equal,
 * it sets the first variable to 1 and increments the second variable by 1.
 *
 * @value: Pointer to the first integer variable.
 * @increment: Pointer to the second integer variable.
 */
void update_values(int *value, int *increment)
{
if (*value == 4)
{
*value = 1;
(*increment)++;
}
}

/**
 * menger - Generates a Menger sponge
 * @level: The level of detail of the Menger sponge
 *
 * Description: This function generates a Menger
 * sponge fractal using the console.
 * The level of detail of the sponge is determined
 * by the 'level' parameter, where a higher number results in a more detailed
 * sponge. The sponge is generated using nested for loops and a series of if
 * statements that handle the positioning and printing of either a '#'
 * character or a space. The position and dimension
 * variables are incremented and reset as needed within the loops.
 */
void menger(int level)
{
int size = pow(3, level);
int y, x, posx = 1, posy = 1, row = 1, col = 1, c1 = 1;
int r1 = 1, r2 = 1, c2 = 1, r3 = 1, c3 = 1, r4 = 1, c4 = 1;

for (y = 1; y <= size; y++)
{
for (x = 1; x <= size; x++)
{
update_values(&posx, &col);
update_values(&col, &c1);
update_values(&r1, &r2);
update_values(&r2, &r3);
update_values(&r3, &r4);
if (r4 == 4)
    r4 = 1;
update_values(&c1, &c2);
update_values(&c2, &c3);
update_values(&c3, &c4);
if (c4 == 4)
    c4 = 1;
print_menger(posx, posy, col, row, c1, r1, r2, c2, r3, c3, r4, c4);
posx++;
}
set_values(&c4, 1);
set_values(&c3, 1);
set_values(&c2, 1);
set_values(&c1, 1);
set_values(&col, 0);
if (posy == 3)
    row++;
update_values(&row, &r1);
if (posy == 4)
    posy = 1;
update_values(&c1, &c2);
update_values(&c2, &c3);
update_values(&c3, &c4);
printf("\n");
posy++;
}
}

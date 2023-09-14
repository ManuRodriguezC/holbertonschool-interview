#include "sandpiles.h"
#include <stdio.h>
#include <stdbool.h>

/**
 * add_grid - Add two grids, grid2 to grid1.
 * @grid1 Grid 1 that add to greid 2.
 * @grid2: Grid 2'
 * Return: The new grid
 */
void sum_grids(int grid1[3][3], int grid2[3][3])
{
	size_t row, col;

	for (row = 0; row < 3; row++)
    {
		for (col = 0; col < 3; col++)
			grid1[row][col] += grid2[row][col];
	}
}

/**
 * copy_grid - This function copy the grid.
 * @origin: The grid to copy.
 * @copy: The copy of the grid.
 * Return: nothing, the copying is done in-place.
 */
void copy_grid(int origin[3][3], int copy[3][3])
{
	size_t row, col;

	for (row = 0; row < 3; row++)
    {
		for (col = 0; col < 3; col++)
			copy[row][col] = origin[row][col];
	}
}

/**
 * copy_and_topple - Simulete if topple is stable
 * Create a future copy and encode it accordingly
 * to be able to determine if it is stable in
 * the event that it does not, set each position
 * and add the positions one by one next to the position.
 * @current_grid: Grid current
 * @future_grid: grid ti copy of the futures values.
 * Return: true if 'current_grid' was stable,
 * false if 'current_grid' wasn't stable.
 */
bool copy_and_topple(int current_grid[3][3], int future_grid[3][3])
{
	size_t row, col;
	bool grid_was_stable = true;

	/*
	 * Check if the value of teh sandpiles > 3.
	 * If such cell is found, then result can
	 * be turned to false then.
	 */

	copy_grid(current_grid, future_grid);

	for (row = 0; row < 3; row++)
    {
		for (col = 0; col < 3; col++)
        {
			if (current_grid[row][col] > 3)
            {
				grid_was_stable = false;

				future_grid[row][col] -= 4;

				if (row > 0)
					future_grid[row - 1][col]++;
				if (row < 2)
					future_grid[row + 1][col]++;
				if (col > 0)
					future_grid[row][col - 1]++;
				if (col < 2)
					future_grid[row][col + 1]++;
			}
		}
	}

	return (grid_was_stable);
}

/**
 * print_grid - Print 3x3 grid
 * @grid: 3x3 grid
 *
 */
static void print_grid(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (j)
				printf(" ");
			printf("%d", grid[i][j]);
		}
		printf("\n");
	}
}

/**
 * sandpiles_sum - This function check if teh sandpiles is stable.
 * When to add both grids, need to found is sandpiles is stable,
 * if it's not stable, they neet to tray again
 * and set tne valus of teh sandpiles.
 * @grid1: The grid which will have the sandpiles from the
 * other grid dumped on, and have sandpile toppling rounds
 * simulated with
 *
 * @grid2: The grid of sandpiles to dump on 'grid1'
 *
 * Return: None
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	sum_grids(grid1, grid2);

	do {
		int future_grid[3][3];

		bool grid1_was_stable = copy_and_topple(grid1, future_grid);

		if (grid1_was_stable)
			break;

		puts("=");
		print_grid(grid1);

		copy_grid(future_grid, grid1);
	} while (true);
}
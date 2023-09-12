#include <stdlib.h>
#include <stdio.h>

/**
 * sanpiles_sum: Function sum 2 sandpiles
 * @grid1: Left sandpile 3x3
 * @grid2: Right sandpile 3x3
 * Return: Sum that 2 sandpiles
 */
 void sandpiles_sum(int grid1[3][3], int grid2[3][3])
 {
    int size, tall;

    for (size = 0; size < 3; size++) {
        for (tall = 0; tall < 3; tall++) {
            grid1[size][tall] = grid1[size][tall] + grid2[size][tall];
        }
    }
 }
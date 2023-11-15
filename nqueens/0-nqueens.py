#!/usr/bin/python3
""" This module created code solution to the
N-queens problem using backtracking. """
import sys


def solve_n_queens(N):
    """
    Solves the N-Queens problem using backtracking.
    Args:
        N (int): The size of the chessboard.
    Returns:
        list: A list of solutions, where each solution is a
        list of positions for the queens.
    """
    def is_safe(positions, row, col):
        """
        Checks if a queen can be placed at a given position
        without being attacked by another queen.
        Args:
            positions (list): A list of positions for the queens.
            row (int): The row where the queen is to be placed.
            col (int): The column where the queen is to be placed.
        Returns:
            bool: True if it's safe to place a queen at
            the given position, False otherwise.
        """
        for y, x in enumerate(positions):
            if x == row or abs(x - row) == abs(y - col):
                return False
        return True

    def recursive(col, positions=[]):
        """
        Recursive function that places queens column by column.
        Args:
            col (int): The column to place the queen in.
            positions (list, optional): The current positions of
                he queens. Defaults to [].
        Returns:
            bool: True if a solution was found, False otherwise.
        """
        if col == N:
            solutions.append(positions)
            return True
        for row in range(N):
            if is_safe(positions, row, col):
                recursive(col + 1, positions + [row])
        return False

    solutions = []
    recursive(0)
    return solutions


def print_solutions(solutions):
    """
    Prints the solutions in a readable format.
    Args:
        solutions (list): A list of solutions, where each
        solution is a list of positions for the queens.
    """
    for i, solution in enumerate(solutions):
        options = []
        for row, col in enumerate(solution):
            options.append([row, col])
        print(options)


if __name__ == "__main__":
    """
    The main block that checks the command line arguments and
    calls the solve_n_queens function.
    """
    if len(sys.argv) != 2:
        print("Usage: nqueens N")
        sys.exit(1)
    if not sys.argv[1].isdigit():
        print("N must be a number")
        sys.exit(1)
    N = int(sys.argv[1])
    if N < 4:
        print("N must be at least 4")
        sys.exit(1)
    solutions = solve_n_queens(N)
    print_solutions(solutions)

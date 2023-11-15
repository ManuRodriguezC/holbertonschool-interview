# N-Queens Solver

This Python program is a solution to the N-Queens problem using backtracking. The N-Queens problem is a classic computer science problem where the goal is to place N queens on an NxN chessboard such that no two queens threaten each other. This means that no two queens can be placed in the same row, column, or diagonal.

## Installation

To run this program, you need to have Python 3 installed on your system. If you don't have Python installed, you can download it from the official Python website.

## Usage

To run the program, open a terminal, navigate to the directory containing the script, and run the following command:

```
python3 nqueens.py N
```
Replace N with the size of the chessboard. The program will print all solutions for the N-Queens problem.

## Functions

The program contains two main functions:

* solve_n_queens(N): Solves the N-Queens problem using backtracking. It takes the size of the chessboard as an argument and returns a list of solutions, where each solution is a list of positions for the queens.

* print_solutions(solutions): Prints the solutions in a readable format. It takes a list of solutions as an argument.
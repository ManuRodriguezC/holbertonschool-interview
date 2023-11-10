# Menger Sponge
This project generates a Menger sponge, a three-dimensional fractal figure. The sponge is generated using a console and the level of detail is determined by a parameter.

## Files
This project consists of four files:

* 0-main.c: This is the main file that executes the program.
* 0-menger.c: This file contains the function menger() that generates the Menger sponge.
* menger.h: This file contains the library functions used in the program.
* README.md: This file contains information about the project.

### How to Run the Program

To run this program, you need to compile and run the 0-main.c file. If you are using gcc, you can do this by opening a terminal in the project directory and typing:

```
gcc -Wall -Wextra -Werror -pedantic -o 0-menger 0-menger.c 0-main.c -lm

./0-menger

The first command compiles the 0-main.c and 0-menger.c files and outputs an executable file named menger. The second command runs the executable.
```

```
./0-menger 3

###########################
# ## ## ## ## ## ## ## ## #
###########################
###   ######   ######   ###
# #   # ## #   # ## #   # #
###   ######   ######   ###
###########################
# ## ## ## ## ## ## ## ## #
###########################
#########         #########
# ## ## #         # ## ## #
#########         #########
###   ###         ###   ###
# #   # #         # #   # #
###   ###         ###   ###
#########         #########
# ## ## #         # ## ## #
#########         #########
###########################
# ## ## ## ## ## ## ## ## #
###########################
###   ######   ######   ###
# #   # ## #   # ## #   # #
###   ######   ######   ###
###########################
# ## ## ## ## ## ## ## ## #
###########################
```

Created by ManuRodriguezC 


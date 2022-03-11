/**
 *
 *
 * The Lo Shu Magic Square has the following properties:
 * - The grid contains the numbers 1 through 9 exactly.
 * - The sum of each row, each column, and each diagonal all add up to the same number.
 *
 *
 * Create a program by simulating a magic square using a two-dimensional array.
 * Write a function that accepts a two-dimensional array as an argument,
 * and determines whether the array is a Lo Shu Magic Square.
 * Test the function in a program.
 *
 * 1) Create the program and test with an array that is a Lo Shu Magic Square and test
 * where it is not.
 * The array’s can be defined in your main and should not need to be input from the user.
 *
 * 2) Create and populate a two-dimensional array with random numbers from 1-9.
 * Recall no number should repeat when populating the array.
 * Then check if it is a Lo Shu Magic Share.
 * Put this random number placement in a loop until you do get a Lo Shu Magic Square.
 * Print two things:
 * a. The total number of squares generated and tested before success, the count.
 * b. Print the square and show the placement of values in the following format
 [a  b  c]
 [d  e  f]
 [g  h  i]
 *
 *
 * */

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

// The Lo Shu Magic Square is a grid with 3 rows and 3 columns.
#define ROW_COL 3


// global variable
int grid[ROW_COL][ROW_COL];

_Bool isLoShuMagicSquare(int grid[ROW_COL][ROW_COL]);

int *nonRepeated_Randoms ();


/*
 * Create a program by simulating a magic square using a two-dimensional array.
 * Write a function that accepts a two-dimensional array as an argument,
 * and determines whether the array is a Lo Shu Magic Square.
 */
_Bool isLoShuMagicSquare(int grid[ROW_COL][ROW_COL]) {

    // check on each row's sum
    int sum_row = grid[0][0] + grid[0][1] + grid[0][2];

    // compare it with Top_Left to Bottom_Right diagonal sum
    if ( (grid[0][0] + grid[1][1] + grid[2][2]) != sum_row ) {
        return 0;
    }


    // compare it with Top_Right to Bottom_Left diagonal sum
    if ( (grid[0][2] + grid[1][1] + grid[2][0]) != sum_row ) {
        return 0;
    }


    for (int row = 1; row < ROW_COL; ++row) {
        if ( (grid[row][0] + grid[row][1] + grid[row][2]) != sum_row ) {
            return 0;
        }
    } // end of checking row's sum

    for (int col = 0; col < ROW_COL; ++col) {
        if ( (grid[0][col] + grid[1][col] + grid[2][col]) != sum_row ) {
            return 0;
        }
    } // end of checking col's sum


    return 1;
}


/* Create and populate a two-dimensional array with random numbers from 1-9.
 * Recall no number should repeat when populating the array.
 */
// generate a two-D array with different numbers from 1 to 9
int *nonRepeated_Randoms () {

    int i = 0, j;
    int total = ROW_COL * ROW_COL;

    int *array = (int *) malloc(sizeof(int) * total);

    if (array == NULL) {
        printf("Failed to allocate memory...\n");
        EXIT_FAILURE;
    }

    while (i < total) {

        int n = rand() % 9 + 1;

        for (j = 0; j < i; j++) {

            if (*(array + j) == n) {
                break;
            }
        } // end of inner for loop

        if (j == i) {
            *(array + i) = n;
          //  printf("%d\t", *(array + i));
            ++i;
        }

    }
    return array;
}



int main(void)
{
    
    // initialize a grid with 3 rows and 3 columns without asking user input
//    int test[ROW_COL][ROW_COL] = { {4, 9, 2},
//                                   {3, 5, 7},
//                                  {8, 1, 6}
//    } ;
//
//    isLoShuMagicSquare(test);


    srand(time(NULL));
    int counter = 0;

    do {

        int *array = nonRepeated_Randoms();

        printf("\n");

        int index = 0;

        for (int i = 0; i < ROW_COL; ++i) {

            for (int j = 0; j < ROW_COL; ++j) {
                grid[i][j] = (*(array + index));
               // printf("%-2d", grid[i][j]);
                ++index;
            }

            printf("\n");
        }
        free(array);

        ++counter;

    } while (isLoShuMagicSquare(grid) == 0);


    printf("Counter = %d\n", counter);

    for (int i = 0; i < ROW_COL; ++i) {
        printf("[ ");

        for (int j = 0; j < ROW_COL; ++j) {
            printf("%-2d", grid[i][j]);
        }

        printf("]\n");
    } // end of for

   

    return 0;

}



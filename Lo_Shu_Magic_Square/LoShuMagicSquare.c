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
#include<stdarg.h>

// The Lo Shu Magic Square is a grid with 3 rows and 3 columns.
#define ROW_COL 3


/*
 * Create a program by simulating a magic square using a two-dimensional array.
 * Write a function that accepts a two-dimensional array as an argument,
 * and determines whether the array is a Lo Shu Magic Square.
 */
_Bool isLoShuMagicSquare( int twoDArray[ROW_COL][ROW_COL]) {

    // main diagonal 1 = [1][1] + [2][2] + [3][3]
    // main diagonal 2 = [3][1] + [2][2] + [1][3]
    int sum_mainDiagonal1 = 0, sum_mainDiagonal2 = 0;

    int sum_col[ROW_COL];

    for (int row = 0; row < ROW_COL; ++row) {

        int sum_row = 0, sum_col = 0;
        int prev1 = 0, prev2 = 0;

        sum_mainDiagonal1 += twoDArray[row][row];
        sum_mainDiagonal2 += twoDArray[row][ROW_COL - 1 - row];

        for (int col = 0; col < ROW_COL; ++col) {
            sum_row += twoDArray[row][col];
            sum_col += twoDArray[col][row];
        }

        prev1 = sum_row;
        prev2 = sum_col;

        if (row > 0) {

            if (sum_row != prev1) {
                return 0;
            }
            if (sum_col != prev2) {
                return 0;
            }
        }

        for (int col = 0; col < ROW_COL; ++col) {
            printf("%2d", twoDArray[row][col]);
        }


    } // end of for loop

    if (sum_mainDiagonal1 != sum_mainDiagonal2) {
        // printf("%d != %d\n", sum_mainDiagonal1, sum_mainDiagonal2);
        return 0;
    }

    printf("\n--------------------------------\n");

    return 1;
}


/* Create and populate a two-dimensional array with random numbers from 1-9.
 * Recall no number should repeat when populating the array.
 */

// generate a two-D array with different numbers from 1 to 9
int *nonRepeated_Randoms () {

    srand(time(0));

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
            printf("%d\t", *(array + i));
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

    int *array = nonRepeated_Randoms();

    printf("\n");

    int n = ROW_COL * ROW_COL;
    int grid[ROW_COL][ROW_COL];
    int new_line = 0;

    for (int i = 0; i < n; ++i) {

        printf("%-2d", *(array + i));

        if (i % 3 == 2) {
            printf("\n");
            grid[new_line++][i] = *(array + i);
        }
    }
    free(array);

    printf("\n\n\n");

   // isLoShuMagicSquare(grid);

    if (isLoShuMagicSquare(grid) == 1) {
        printf("It's a lo shu magic square!\n");
    } else {
        printf("It's NOT somewhat magic can happen everytime.\n");
    }

    return 0;

}

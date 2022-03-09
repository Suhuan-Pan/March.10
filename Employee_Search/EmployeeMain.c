/*
 * Update employeeMain.c
 * EmployeeSearch
 *
a) Call this branch – search-multiple-function
[employeeOne.c]

 - Complete searching the table for the other entries by creating search
functions for the other two entries.

 - Search by number and name have already been completed.

 - Complete search by phone number and salary.

 - Show example of a match and no match in each of your functions.

 Hence, 4 cases total -> Update employeeMain.c

 ----------------------------------------------------------------------

b) Call this branch – single-search-pass-function
employeeTwo.c

 - Complete searching the table for other entries by passing in the function that will perform the search.
 (Make sure employeeOne.c is not located in this branch.)

NOTE: employeeMain.c should be the same for both of the implementations above.
 */

#include <string.h>
#include <stdlib.h>
//
#include "Employee.h"
#include "EmployeeOne.c"
#include "EmployeeTable.c"

int main()
{
   // const int num = EmployeeTableEntries;
  //  printf("Number of entries = %d\n", num);

    printf("\n------ Current branch: search-multiple-function, testing EmployeeOne.c -----\n\n");

    /*** ---------- defined in employeeSearchOne.c ---------- ***/
    PtrToEmployee searchEmployeeByNumber(const Employee table[], int sizeTable, long numberToFind);

    PtrToEmployee searchEmployeeByName(const Employee table[], int sizeTable, char * nameToFind);


   // ---------- defined in employeeTable.c ----------
    extern Employee EmployeeTable[];

    extern const int EmployeeTableEntries;

    // ---------- Declaration ----------
    PtrToEmployee matchPtr;

    /* ------------------------------------------------------------ */
    // Example found
    matchPtr = searchEmployeeByPhoneNumber(EmployeeTable, EmployeeTableEntries, "310-555-1215");
    if (matchPtr != NULL) {
        // printf("=== current ptr at %p, table ptr at %p\n", *matchPtr, *EmployeeTable);
        printf("Employee phone number 310-555-1215 is in record [%ld]\n", matchPtr - EmployeeTable);
    } else {
        printf("Employee phone number is NOT found in the record.\n");
    }

    /* ------------------------------------------------------------ */
    // Example not found
    matchPtr = searchEmployeeBySalary(EmployeeTable, EmployeeTableEntries, 100.00);
    if (matchPtr == NULL) {
        printf("Employee salary is not found in the record.\n");
    } else {
        printf("Employee salary %f is in record [%ld]]n", 100.00, matchPtr - EmployeeTable);
    }


    /* ------------------------------------------------------------ */
    // Example not found
    matchPtr = searchEmployeeByNumber(EmployeeTable, EmployeeTableEntries, 1045);
    if (matchPtr != NULL) {
        // %ld
        printf("Employee ID 1045 is in record [%ld]\n", matchPtr - EmployeeTable);
    } else {
        printf("Employee ID is NOT found in the record.\n");
    }

    /* ------------------------------------------------------------*/
    // Example found
    matchPtr = searchEmployeeByName(EmployeeTable, EmployeeTableEntries, "Tony Bobcat");
    if (matchPtr != NULL) {
       // printf("=== current ptr at %p, table ptr at %p\n", *matchPtr, *EmployeeTable);
        printf("Employee Tony Bobcat is in record [%ld]\n", matchPtr - EmployeeTable);
    } else {
        printf("Employee Tony Bobcat is NOT found in the record.\n");
    }

    /*** ---------- END defined in employeeSearchOne.c ---------- ***/

    EXIT_SUCCESS;
}

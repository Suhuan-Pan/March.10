/**
 * EmployeeOne.c --- searching option 1,
 * branch: search-multiple-function
 *
 *  -------------------------------------
 * - Search by number and name have already been completed.
 * @Lecture 11 Notes
 *
 * - Search by salary / search by phone number
 * @In-Class_Quiz 2
 *
 *
 */

#include <string.h>
#include "Employee.h"

/*** Declare in Employee.h: typedef const Employee *PtrToConstEmployee; ***/

// search by phone number
PtrToEmployee searchEmployeeByPhoneNumber (PtrToConstEmployee ptr_to_employee,
                                           int tableSize,
                                           char * targetPhoneNumber) {

    const PtrToConstEmployee endPtr = ptr_to_employee + tableSize;

    //search until end of table
    for(; ptr_to_employee < endPtr; ptr_to_employee++) {

      //  printf("=== Pointer points at: %s ===\n", ptr_to_employee->phone);

        //check if it equals the Employee's phone number, strcmp() returns zero if equals
        if ( strcmp(ptr_to_employee->phone, targetPhoneNumber) == 0 ) {
            return (PtrToEmployee) ptr_to_employee;
        }
    }

    // if no employee's phone number matches in the for loop above:
    return NULL;
}

/*-------------------------------------------------- */
// search by salary
PtrToEmployee searchEmployeeBySalary (PtrToEmployee ptr_to_employee,
                                      int tableSize,
                                      double targetSalary) {

    // calculate the end location after loop through all entries
    // return a const pointer (address) of Employee
    const PtrToConstEmployee end_ptr = ptr_to_employee + tableSize;

    for (; ptr_to_employee < end_ptr; ptr_to_employee++) {

        if (ptr_to_employee->salary == targetSalary) {
            // type cast
            return (PtrToEmployee) ptr_to_employee;
        }
    }

    // return NULL of not found
    return NULL;
}

/*-------------------------------------------------- */

/* search for a particular employee by employee's number
// compare number value to table's number value (<, > or ==)
// traversal the whole table
 */
PtrToEmployee searchEmployeeByNumber(PtrToConstEmployee ptr,
                                     int tableSize,
                                     long targetNumber) {

    const PtrToConstEmployee endPtr = ptr + tableSize;

    //search until end of table
    // ptr++ will increment to access next entry
    for(; ptr < endPtr; ptr++) {

        // %d specify for long targetNumber, still use -> to access
      //  printf("=== Pointer points at ID #%d ===\n", ptr->number);

        //check if it equals the Employee number
        if (ptr->number == targetNumber) {
            return (PtrToEmployee) ptr;  // return LOCATION of the number to caller
        }
    }

    // if no employee number matches in the for loop above:
    return NULL;
}

/*-------------------------------------------------- */
/* search for a particular employee by employee's name
// compare strings to check if equal
// traversal the whole table
 */
PtrToEmployee searchEmployeeByName(PtrToConstEmployee ptr,
                                   int tableSize,
                                   char *targetName) {

    const PtrToConstEmployee endPtr = ptr + tableSize;

    //search until end of table
    for(; ptr < endPtr; ptr++) {

    //    printf("=== Pointer points at: %s ===\n", ptr->name);

        //check if it equals the Employee name, strcmp() returns zero if equals
        if ( strcmp(ptr->name, targetName) == 0 ) {
            return (PtrToEmployee) ptr;  // return LOCATION of the name to caller
        }
    }

    // if no employee name matches in the for loop above:
    return NULL;
}


/*
 * EmployeeTwo.c
 * b) Call this branch – single-search-pass-function
 *
 * 
 - Complete searching the table for other entries by passing in the function
 that will perform the search.
 (Make sure employeeOne.c is not located in this branch.)
 
 * NOTE: employeeMain.c should be the same for both of the implementations above.
 *
 */

#include <string.h>
#include "Employee.h"



/****************** @lecture 11 notes ******************/
/**
 * @param ptr - points to table to be searched
 * @param tableSize - size of the table
 * @param targetPtr - points to value that will be searched for in table
 * @param functionPtr
 * - points to a comparison below
 * - and will perform the associated check
 *
 * what does setting a function to static do?????
 *
 * functionPtr is the address of the function just used the name
 * ()(the second set of parentheses is the arguments of the function call
 */
static PtrToEmployee searchEmployeeTable ( PtrToConstEmployee ptr, int tableSize, const void *targetPtr,
                                           int (*functionPtr)(const void *, PtrToConstEmployee) ) {

    // not const PtrToConstEmployee
    PtrToConstEmployee endPtr = ptr + tableSize;

    for(; ptr < endPtr; ptr++) {

        if ( (*functionPtr)(targetPtr, ptr) == 0 ) {
            return (PtrToEmployee) ptr;
        }
    }

    return NULL;
}

// the functionPtr will point to one of these comparison functions to perform a check
static int compareEmployeeNumber (const void *targetPtr, PtrToConstEmployee tableValuePtr) {

    // const void *targetPtr ==> typecast as int pointer then dereference
    return * (long *) targetPtr != tableValuePtr->number;
}

static int compareEmployeeName (const void *targetPtr, PtrToConstEmployee tableValuePtr) {

    // const void *targetPtr ==> typecast as char pointer then pass into strcmp()
    return strcmp( (char *) targetPtr, tableValuePtr->name );
}

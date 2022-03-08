/*
 * Employee.h
 *
 * a header file -- declare an anonymous structure Employee,
 * and a pointer points to the entire structure;
* @Lecture 11 Notes
 *
 */

#pragma once // guard the header Employee.h
#include <stdio.h>
#include <stddef.h>

typedef struct {

   long number; // 4-bytem <-- Padding -->

   char *name; // <------ 8-byte ------>

   char *phone; // <------ 8-byte ------>

   double salary;

} Employee, *PtrToEmployee;

typedef const Employee *PtrToConstEmployee;


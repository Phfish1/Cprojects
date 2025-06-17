#include<stdio.h>
#include<stdlib.h>

//
// Declaration VS Definition
//      Declaration: Tells the Compiler the TYPE and NAME of a VARIABLE
//      Definition: Allocates Memory for a VARIABLE declaration
//
// Initialized VS Uninitialized
//      Uninizialized: Variable has been Declared(most likely also Defined) but has no Value / Garbage_random Value
//      Initialized: Variable has been Defined in memory and has a Value
// 
//    MOST of the time all variables in '.c' files are Defined
//    Unless you are using External Variables where the definition of which are in other files.

extern int Uninitialized_Declaration;

int main() {

    int Uninitialized_Definition;
    int Initialized_Definition = 99;

    // How much StackMemory does a pointer allocate?
    //      It needs to allocate space for a Variable which stores an Address as a Value

    // Declares a variable p1 which holds a pointer
        int* p1;
    //      But nothing else, THE POINTER does NOT point to a valid Memory Location
    //      It is JUST declared a variable that holds a Memory Address
    // If you try to dereference or write to the value p1 points to, you will get a random address and SEG FAULT!
    //
    // This is called an UNITIALIZED Pointer


    //
    // What we need to do, is allocate memory enough to store an Integer 

    // Integer Variable: 4 Bytes
    int i; // Uninitialized Integer
    // Pointer Variable: 8 Bytes
    int* p; // Uninitialized Pointer

    // Then assign to 'p' the address of 'i'
    p = &i;

    // And if you want Assign a Value to 'i' ie( which address of so is stoed in 'p' )
    //      i = 10;
    //      OR
    //      *p = 10

    *p = 10;
    printf("Number: %d\n", *p);

    // Uninitialized just means it has NOT been assigned a Value
    int j;       // Integer (Unitialized)
    int *p2;    // Pointer to an Integer (Unitialized)

    p2 = &j;     // Initializing 'p2'
    *p2 = 92;     // Initializing 'j' (Via address at p2)

    printf("Number: %d\n", *p2);

    return 0;
}

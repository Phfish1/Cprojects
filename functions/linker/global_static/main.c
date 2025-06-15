#include<stdio.h>
#include<stdlib.h>
// I take a look at the Assembly in arrayTest.s for static variables


// ==== Static Variables ====
//
// Variables that are stored in the Executible Binary
// AND
// That are ONLY ussable inside the functions of the source-file it was created from
// 
// BUT static variables are defined by Function Scopes,
//      They are not deleted when a return statment "destroys" the Stack-Frame
//      But the reference to them are function-scope local
// ALTOUGH:
//          You can return a static variable if it is defined in a called function!
//          Because the address you are returning is not within the called function 
//              !!! AS LONG AS YOU RETURN THE ADDRESS !!! and not the value inside of the variable 
//                  return &i           YES
//                  return i            NO
//
// Importantly because they are stored in the .bss or .data section they retain their values
// accross function calls.
//

//
// ==== Global Variables ====
//  
// Non-function-scoped
//      meaning you can access variables defined here in any function in the program
//
// Global variables are not explicitly defined, but are just scoped outside any specific function.
//      They can therefore not be apart of a Stack-Frame and is therefore stored in the Executable Binary
//      Either in the .bss or .data section
//
// Defining variables in the global scope without the static keyword
// Makes them accessible in other files,
//      If static is used, the variable is only accesible to the source file
//

//
// === How this works ===
//
// We define variables as named "boxes" which holds a specefic type of data
// This variable is then compiled to assembly < Symbols >
//
// Symbols are references to Memory Addresses!
//
// The next step in the compilation is linking
//      The linker then takes our Symbols, and if they are global
//      are accessible to all the files the linker links.
//
// The linker resolves Symbols to actuall Memory addresses

//
// === Linker ===
//
// The linker takes multiple Object files with Symbols and resolves them to Memory Addresses
//      So if i include a file or library like <stdio.h> the linker will look in that file when an symbol in our source-file
//      is not found within it.
//
// For example you usethe function printf(), it is not defined locally within our file
//      Therefore the linker looks for it in <stdio.h>
//
//  Or if you have a global variable in file1
//      int i = 10;
//  And reference the symbol "i" in file2
//      The linker will lookup the symbol i in file1 if it is #included
//
// The Linker then resolves the symbol "i" to a Memory Address
//      Which it places in both files, (it mixes them together) into 1 program, [Aka the name: linker]
//
// This allows us to use libraries without needing to compile them again every time
//      By linking in another Object file

//
// === Declaration VS Definition ===
//
// A Declaration
//      int variable;
//  Decleares that a variable exists and assigns a symbol name to it
//
// A Definition
//          int variable = 15;
//      Defines the Symbol Name and the Value it points to. (This can be a Memory Address)
//          int variables[5];
//      Defines an Array with the value at variables being a Memory Address
//
//  Importantly a Definition ALLOCATES MEMORY while a Decleration only defines a symbol name and which type of data it holds

//
// === Extern Variables ===
//
// You can -> Declare <- an External variable
//      extern int fromAnotherFile;
//
// Specifying the type and the symbol name
//      It being external means that the LINKER will look trough all the files LINKED trying to find the symbol "fromAnotherFile"
//      and resolve the Memory Address which was in another file DEFINED.
//
// This means that the external declaration will get its value and Memory Allocation from another file.
//      Another file has the DEFINITION, and in our file we are only DECLARING it, so we can also use it.
//

// This is a global variable
int useMeOtherFile = 69;

// This is a Static variable
static int thisFileOnly = 420;

extern int fromAnotherFile;

// Function usable from other files
int* fileGlobalFunction() {
    static int staticDefinition = 10;
    printf("Defined static variable: %d \nAt the address: %p\n\n", staticDefinition, &staticDefinition);

    return &staticDefinition;
}

// Function only usable in this local file
static int fileSpeceficFunction() {
    return 0;
}

int main() {

    // What are Global and Static variables?
    //      Variables that are stored in the Binary Executable of your program.
    //

    // ==== Stack Variables ====
    //
    // When you define a variable inside a function
    //      That variable is stored on the Functions Stack-Frame
    //      "Only" accessible inside the local function
    //          if main() calls another function, you can pass the other function the value stored inside of a,
    //          OR a pointer to a, which is stored in main()'s Stack-Fram
    //
    //      This variable is thrown away when the function exits
    //          and if you try to return a pointer to a function-local (on the Stack-Frame) variable it will cause an compile-error
    //


    thisFileOnly = 10;
    useMeOtherFile = 11;
    
    int a = 10; // On the stack and local to main()

    int* staticDefinition = fileGlobalFunction();
    printf("The function returned the address to: %d (static variable at) => %p\n", *staticDefinition, staticDefinition);

    printf("\nDefinition from another file: %d\n", fromAnotherFile);

    return 0;
}

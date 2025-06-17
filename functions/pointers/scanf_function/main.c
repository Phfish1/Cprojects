#include<stdio.h>

int main() {


    // You define or declare a variable
    //      int i;
    //      int j = 10;
    //
    // Then when you reference the variable name ie 'i' or 'j'
    // You refer to the VALUE at the variable name.
    //      If you use 'j' in any way printf("%d", j+10);
    //      You will get the VALUE of 'j' pluss 10
    //
    // You can also reassign the value at 'j'
    //      j = 15;
    // This referes to the value stored at 'j'
    //

    // 
    // But a variable is comprised of two things
    //      Memory Address
    //      Value
    // So instead of dereferencing a Memory Address all of the time, you use a variable.
    // BUT, if you want to pass a function or use the Memory Address of a Variable
    //      You use the Ampersant character '&'
    //
   
    // You have a Variable(Address+Value) "input"
    //      I want scanf to put a value the user inputs inside of my variable "input"
    //      Therefore i must pass the ACTUALL address where my Value is stored
    //          If i dont use the '&' symbol (or a pointer) i will pass scanf the VALUE of 'input' (0)
    //

    int input;
    puts("Enter a number: ");

    scanf("%d", &input);
    printf("You entered: %d\n", input);

    //
    // Alteretivly instead of using the '&' symbol, You can define input as a pointer.
    //      Pointer being a variable that holds an memory address
    //
    //      Altough this is less efficient as you have a variable, holding a value (memory address)
    //      But that Variable holding the Value (memory address) also has an Address of which it is stored
    //
   
    int x;
    int* input2 = &x;


    puts("Enter another number: ");
    scanf("%d", input2); 


    printf("Value at input2: %p\n", input2);
    printf("Address of input2: %p\n", &input2);

    //
    // You can the use the symbol '*' To dereference a Memory Address stored in a Variable
    //      *input2; gives you the VALUE that the Memory Address value at input2 referes/point to
    //

    printf("Value of address pointed to by input2(%p): %p\n", input2, *input2);

    // 
    // This means you could also do (to get the value of input2)
    //      Dereference input2 (to get value): *input2
    //      Then ask which address that value is stored: &*input2
    //

    return 0;
}

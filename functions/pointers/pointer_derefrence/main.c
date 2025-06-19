#include<stdio.h>
#include<stdlib.h>

int main() {

    // Using malloc to Allocate Memory to 1 Integer
    int* ip = malloc(sizeof(int) * 1);
    
    // *ip points to an Integer.
    //      We can dereference an Integer in a function like this
    //          printf("Print value *ip points to: %d, *ip);
    //  Using the '*' character to DEREFRENCE
    //
    //  But what if we want to ASSIGN a value to the memory *ip points to?
    //      We simply use *<VAR> on the right side like so
    //          *ip = <value>
    //
    
    *ip = 12;

    // Then of course you can Derefrence it and store the value *ip point to elsewhere
    int value = *ip;


    printf("*ip: %d\nvalue: %d\n", *ip, value);



    return 0;
}

#include<stdio.h>
#include<stdlib.h>


int main() {

    // ==== Generic Pointers (void) ====

    // We can define a pointer using the '*' on the LEFT side of our Decleration/Definition 
    //      BUT we need to specify the POINTER TYPE.
    // 

    // We can define a GENERIC Pointer type using the 'void' keyword
    //      'vp' is now just a Variable defined to hold a Memory Address
    void* vp;

    int i = 10;

    // We then assign the Address of 'i' to our Generic Pointer 'vp'
    vp = &i;
   

    // Now 'vp' stores the address of 'i', but there is a problem...
    //      Since a void pointer can store ANY type of pointer
    //      How does our compiler know how to dereference / Interprete the Value at the the address stored in vp???
    //
    // If we try to dereference the pointer
    //      printf("%d", *vp);
    // We get an Error
    //      Our compiler does not know what SIZE of the VALUE our pointer Points to!
    //      Therefore does now know how many bytes to read, or how to interpret it!

    //
    // That is why you should define the TYPE of your Pointers
    //      So the compiler knows how many Bytes to read of when dereferencing our pointer and accessing the Value stored.
    //


    // ==== Defining Integer Type Pointer ====

    int *ip;
    ip = &i;

    // Our compiler now knows how many bytes to READ of the data pointed to by 'ip'
    printf("Value at i: %d\n\n", *ip);


    // ==== TypeCasting ====

    // Sometimes we want to Define a Pointer that points to a Generic Value
    //      Do such by using a void pointer 'void* vp'
    //

    // But for our program to know how many bytes to read of the data pointed to
    //      We need to SPECIFY what Type of Data is stored in our pointers
    //  
    // This is called TypeCasting, in this case we TypeCast a Generic Pointer into an Integer Pointer
    //      So that our program knows how much data to read.
    //
    //  TypeCast like this:
    //      int *ip = (int*)vp;
    //      int i = *(int*)vp;
    // 
    // The (int*) Makes our program interpret the variable after 'vp' as an Integer Pointer (int*)
    //
    // Doing *(int*) will TypeCast our Generic Pointer (void pointer) into an Integer Pointer THEN Dereference it.
    //

  
    // Defining Generic void Pointer and pointing it to 'j'
    int j = 88;
    void* vp2;
    vp2 = &j;

    // Typecasting 'vp' to (int*)
    int *ip2 = (int*)vp2;
    int x = 12 + *(int*)vp2;    // Also Dereferencing vp2 as an Integer Pointer

    // Using TypeCasted variables
    printf("Value pointed to by ip2->j: %d\n", *ip2);
    printf("Value at x: %d\n\n", x);

    // TypeCasting AND Dereferencing Void Pointers:
    printf("Value at i: %d\n", *(int*)vp);
    printf("Value at j: %d\n", *(int*)vp2);

    return 0;
}

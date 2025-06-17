#include<stdio.h>  // Standard Input and Output writing libraries
#include<stdlib.h> // Where Malloc etc, and free is Decleared 

void function(int* i) {
    *i += 12; 


    return;
}

int main() {

    // Using pointers to share values
    //      You have a variable, and such variable can be referenced multiple times by different pointers
    //      So when the Value changes multiple variables can dereference themself and accept the fact.

    int i = 87;

    int* ip1 = &i;
    int* ip2 = &i;

    i++;

    printf("Pointers pointing to same location:\nip1: %p\nip2: %p\n*ip1: %d\n*ip2: %d\n", ip1,ip2,*ip1,*ip2);
    printf("\n\n");

    // Malloc Allocates the amount of bytes you specify for it.
    //      malloc(11)
    // Allocates 11 Bytes, and returns a VOID pointer to the first Byte of the Allocated data
    //

    int* data = (int*)malloc(8); // Allocates enough data for 2 Integers (Int=4 Bytes)

    //
    // In C Void Pointers are Implicitly TypeCasted into other Pointer typed!
    // That means that this works
    
    void* vp;
    int* ip = vp;

    // You DONT need a TypeCast here, because Void Pointers are Implicitly typecasted into other datatype POINTERS
    //

    // This is why you dont need to TypeCast Malloc
    int* intArr = malloc(sizeof(int) * 4); 

    // The sizeof() keyword gives you an "size_t" type value indicating the size in Bytes of the expresion you passed it
    //      size_t = Unsigned 64bit Integer (unsigned long long)



    free(data);
    return 0;
}

#include<stdio.h>
#include<stdlib.h>




int main() {

    // You dont NEED to typecast malloc (int*)malloc(<params>)
    // because values is already defined as a int*
    int* values = (int*)malloc(sizeof(int) * 4);
    
    // Malloc returns a Void* Pointer, but it is automatically Type-Casted into an int* because it is assigned to "int* values"

    values[0] = (int)10; 
    values[1] = 15;

    for (int i=0; i < 5; i++) {
        printf("V%d: %d\n", i, values[i]);  
    }
    return 0;
}

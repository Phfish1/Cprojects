#include<stdio.h>
#include<stdlib.h>

int main() {
    // This line does the Memory Allocation for you
    // int array[5]; 

    // By default C stores these types of arrays on the Stack
    int stackArray[5];
    stackArray[2] = 10;

    int i;
    puts("Enter n: ");
    scanf("%d", &i);


    // You can use the static keyword to store the data on the heap
    if (i > 20) {

        // Although this static int WILL ALWAYS, be reserved in the .bss memory section! (no matter what the IF condition yields)
        // So it being inside a if loop only declares how you internally in your program can access it, 

        static int heapArray[5];
        heapArray[2] = 15;
    }

    // Or you can use Malloc() to also store the array data on the Heap
    int* mallocArray = (int*)malloc(sizeof(int)*5);
    mallocArray[2] = 13;


    return 0;
}

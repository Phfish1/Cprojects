#include<stdio.h>
#include<stdlib.h>

typedef struct test {
    int i;
    char *s;
}customType;

int main() {

    // Define a Fixed size array the size of all its entries
    int arr[] = {1,4,6,8,2,3,123,6,89,2,9,6,7};

    // Get the size of that array "Dynamicly"
    //      Store it in a size_t / Unsigned long type

    size_t arrLen = sizeof(arr) / sizeof(arr[0]);

    // This works because sizeof() returns the sizeof(arr) in Bytes: 42
    // And sizeof(arr[0]) returns the sizeof(int) because all items in an array are the same size
    //      Then take 42 / 4 = 13 = Total Entries in Array
    //

    printf("Size of arr: %lu\n", arrLen);


    // Can you use sizeof() on different custom Data Structures?
    //      At least Structs

    printf("size of customType: %lu\n", sizeof(customType));

    // But not very usefull here, as you would probly allocate some memory to *s, which sizeof() could not detect

    return 0;
}



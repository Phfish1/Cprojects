#include<stdio.h>
#include<stdlib.h>

// What do we need to make this work
// - Custom datatype (struct)
// - Factory function (in oop, called Constructor)
// - Function to increase the arraySize

// Custom datatype
typedef struct array {
    int *data;
    size_t size;
}array_t;

// Factory Function
// Sets the struct values of the custom datatype
// Allocates memory

array_t* createArray(int size) {
    // Allocate data to the base array, 2 datatypes (a size_t and an Integer pointer)
    array_t* newArray = (array_t*)malloc(sizeof(array_t));
    
    // Allocates data for the actuall integer data inside *data
    newArray->size = size;
    newArray->data = (int*)malloc(sizeof(int) * size);



    return newArray;
}

array_t* arrCopy(array_t* oldArray) {
    array_t* newArray = createArray(oldArray->size);

    for (int i=0; oldArray->size > i; i++) {
        newArray->data[i] = oldArray->data[i];
    }

    return newArray;

}

// Increases the size of the Array
void incSize(array_t* array, int sizeInc) {
    array_t* oldArray = arrCopy(array);
    
    array->size += sizeInc;
    array->data = (int*)malloc(sizeof(int) * array->size);

    for (int i=0; oldArray->size > i; i++) {
        array->data[i] = oldArray->data[i];
    }
}

int main() {
    array_t* arr = createArray(10);

    arr->data[0] = 10;
    incSize(arr, 5); 

    printf("Sizeof Array: %ld\n", arr->size);
    for (int i=0; arr->size > i; i++) {
        printf("Data[%d]: %d\n", i, arr->data[i]);
    }


    
    return 0;
}

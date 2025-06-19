#include<stdio.h>
#include<stdlib.h>

// You can do TypeCasting using VOID pointers
// multipleTypeVariable = { int, char, float }

enum {
    INT = 1,
    CHAR = 2,
    FLOAT = 3,
};

typedef struct variable_s {
    int type;
    void* value;
}variable_t;

// === Main function for allocating different Types ===
variable_t* createVariable(int type, void* value, size_t value_size) {
    variable_t* var = malloc(sizeof(variable_t));

    var->type = type;
    var->value = (int*)malloc(sizeof(int));

    //
    // We use the '*' sign to to Derefrence the Pointer var->value and store something
    // at the location var->value points to *var->value eg( allocated memory sizeof(int) );
    //      Then TypeCasts the derefrenced pointer to an (Int*)
    //      Because var->value is a Void pointer (Generic Pointer)
    //          We need to specify how the data should be inserted into var->value
    //          For example, char (1byte) values and int(4byte) values are treated different in memory
    //          Therefore we need to specify HOW to write data to the derefrenced *(void*)var->value
    //
    //      We can TypeCast like this:
    //          *(<TYPE>*)<VOID_POINTER> // *(int*)var->value
    //
    //      Telling the compiler to DEREFRENCE a pointer while treating it as a
    //          Integer Pointer.
    //

    *(int*)var->value = 12;

    printf("var->value: %d\n", *(int*)var->value);
    return var;
}

// === Wrapper functions for the specific Value types ===
variable_t* createInt(int value) {
    return createVariable(INT, &value, sizeof(value));

}

// == Then you need a function to GET Variable ===
//      This is so you need not TypeCast it

// This might be tricky or wierd tho... Always some compromises with this aproach... ;(


// Then perhaps wrapper functions

int main() {

    variable_t* x = createInt(10);


    printf("x->value: %d\n", *(int*)x->value);
    return 0;
}



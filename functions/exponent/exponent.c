#include<stdio.h>

long exponent(long base, long exp) {
    // Exceptional 0 case
    if (exp == 0) {
        return 0;
    }

    // Do exponent
    long result = 1;
    for (int i=0; i<exp; i++) {
        result = result * base;
    }

    return result;
}

int main(int argc, char *argv[]) {
    long result = exponent(2, 44);
    printf("Result: %lu\n", result);

    return 0;
}

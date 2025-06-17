#include<stdio.h>

int main() {
    // For loop countdown
    for (int i=10; i >= 0; i--) {
        printf("I: %d\n", i);
    }

    // While loop (over a string / char Array)
    char string[] = "Hello world";
    int crti = 0;
    while (string[crti] != '\0') {
        printf("Char: %c\n", string[crti]);
        crti++;
    }

    // Do Something WHILE is true,
    //      Meaning it will do something first THEN eveluate condition inside WHILE()
    int count = 1;
    do {
        printf("Count: %d\n", count);
        count++;
    } while (count <= 10);
    
    return 0;
}

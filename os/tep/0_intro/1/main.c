#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(int argc, char **argv) {
    int *p = malloc(sizeof(int));

    printf("(%d) Address of p: %p\n", getpid(), p);

    *p = 1;
    while (1) {
        printf("(%d) Value of p: %d\n", getpid(), *p);
        sleep(1);
        *p = *p + 1;
    }

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    char name[50];
    char major[50];
    int age;
    double gpa;
};

struct StrItem {
    char key[50];
    char value[50];
}

struct IntItem {
    char key[50];
    int value;
}

void jsonHandler(char *line, char *depthArr, int depth) {
    int i = 0;
    
    while (line[i] == ' ') {
        i++;
    }
    // Removes whitspace up to first char, placed in wline
    char *wline = line + i;
   // printf("D %s\n", depthArr);
    printf("%s", wline);


    if (wline[0] == '[') {
        depthArr[depth] = '[';
        depth += 1;
    }
    if (wline[0] == ']') {
        depth -= 1;
        depthArr[depth] = ' ';
    }

    if (wline[0] == '{') {
        depthArr[depth] = '{';
        depth += 1;
    }
    if (wline[0] == '}') {
        depth -= 1;
        depthArr[depth] = ' ';
    }

    // Extract the values from the KEY/VALUE pairs
    if (wline[0] == '"') {
        int j = 0;
        while (wline[j] != ':'){
            j++;
        }
        char *value = wline + j+1;
        printf("%s", value);

    }


    return;
}

int openFile() {
    FILE *fptr;
    fptr = fopen("data.json", "r");
    
    // Check if File was found:
    if (fptr == NULL) {
        printf("fptr returned NULL, file does not exist");
        return 0;
    }

    char line[100];

    char depthArr[10];
    int depth = 0;


    // all with depth 2 goes under depth 1, and depth 1 goes under depth 0
    // It will either be under an Array if [] or a struct if {}

    while(fgets(line, 100, fptr)) {
        jsonHandler(line, depthArr, depth);
    }

    //printf("\ndepthArr: %s\ndepth: %d\n", depthArr, depth);
    fclose(fptr);

    return 0;
}

int main() {
    openFile();
    //struct Student student1;

    //strcpy(student1.name, "Philip");
    //strcpy(student1.major, "Computer Science");
    //student1.age = 20;
    //student1.gpa = 4.7;


    //printf("Name: %s\nMajor: %s\nAge: %d\nGPA: %f\n", student1.name, student1.major, student1.age, student1.gpa);

    return 0;
}


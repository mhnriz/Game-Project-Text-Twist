#include <stdio.h>

int main(){

    char myString[100];
    FILE *file;
    file = fopen("GameSets.txt", "r");
    fgets(myString, 100, file);
    printf("%s", myString);
    return 0;
}       
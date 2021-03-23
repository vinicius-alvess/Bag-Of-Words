#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void RemovePoint(char *wordTR){
    char points[] = {',', '.','/','*', ';', '\n', ' ',':'};
    int size = strlen(wordTR);

    for(int i = 0; i<size; i++){
        if(wordTR[size-1] == points[i]){
            wordTR[size-1] = '\0';
        break;
        }
    }
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "RemovePoint.c"

int tolower();

void lowerCase (char *word){
    for(int i = 0; i<strlen(word);i++){
        word[i] = tolower(word[i]);
    }
    return;
}

void calculateBow(FILE *pDictionary, FILE *TR, int *cont, FILE *bowTR){

    char wordD[30]= "";
    char wordTR[30]= "";
    int count = 0;

    fseek(pDictionary, 0, SEEK_SET);
    while (!feof(pDictionary)){
        fseek(TR, 0 , SEEK_SET);
        fscanf(pDictionary, "%s", wordD); 
        while (!feof(TR)){
            fscanf(TR, "%s", wordTR);
            RemovePoint(wordTR);
            lowerCase(wordTR);
            lowerCase(wordD);
        
            if(strcmp(wordD,wordTR) == 0){
                cont[count]++;
            }
        }
        
        fprintf(bowTR, "%s --- %d\n", wordD, cont[count]);
        count ++;
    }
}






#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

double euclidiana (int *pContA, int *pContB, int dictionarySize){
    double distancia = 0;
        for (int i = 0; i < dictionarySize; i++)
        {
            distancia += pow(pContA[i] - pContB[i], 2);
        }
    return distancia = sqrt(distancia);    
}
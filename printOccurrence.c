#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printOccurrences(FILE *dictionary, int *contA, int *contB)
{

    char wordD[20];
    int i = 0;

    fseek(dictionary, 0, SEEK_SET);

    while (!feof(dictionary))
    {
        fscanf(dictionary, "%s", wordD);
        if (contA[i] != 0 || contB[i] != 0)
        {
            printf("\n%s \t|\t %d \t|\t %d", wordD, contA[i], contB[i]);
        }
        i++;
    }
}
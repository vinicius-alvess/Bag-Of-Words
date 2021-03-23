#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int wordCounter(FILE *fileName)
{
    char ch; //Complexidade o(1)
    int words = 1; //Complexidade o(1)

    // Complexidade o(n)
    while (ch != EOF)
    {
        ch = fgetc(fileName);
        if (ch == '\n'){
            words++;
        }
    }

    return words;
}
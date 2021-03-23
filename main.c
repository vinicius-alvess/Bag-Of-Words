#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bows.c"
#include "readDictionary.c"
#include "printOccurrence.c"
#include "euclidiana.c"

int main()
{

    char fileName[30] = "";
    int wordCounters;
    int *pContA, *pContB;
    FILE *pDictionary = NULL;
    FILE *TRA = NULL;
    FILE *TRB = NULL;
    FILE *bowA = NULL;
    FILE *bowB = NULL;
    char opcao;

    //Notação O(1)
    do
    {
        printf("\n################## BAG-OF-WORDS ##################");
        printf("\n");
        printf("\nD - Ler o arquivo de dicionário");
        printf("\nA - Ler arquivo contendo texto de referência A");
        printf("\nB - Ler um arquivo contendo texto de referência B");
        printf("\nT - Exibir BOWs de TRA e TRB");
        printf("\nt - Mostrar similaridade entre os dois textos");
        printf("\nS - Sair");

        printf("\nOpção: ");
        scanf("\n%c", &opcao);

        switch (opcao)
        {
        case 'D':
            printf("\nArquivo de dicionário: ");
            scanf("%s", fileName);
            if (pDictionary != NULL)
            {
                fclose(pDictionary);
            }
            pDictionary = fopen(fileName, "r");
            if (pDictionary == NULL)
            {
                printf("\nNao foi possivel abrir o dicionario\n");
            }
            else
            {
                printf("Dicionario aberto com sucesso!\n\n");
                wordCounters = wordCounter(pDictionary);
                pContA = (int *)calloc(wordCounters, sizeof(int));
                pContB = (int *)calloc(wordCounters, sizeof(int));
                break;
            }

        case 'A':
            printf("\nArquivo de referência A: ");
            scanf("%s", fileName);
            if (TRB != NULL)
            {
                fclose(TRB);
            }
            TRB = fopen(fileName, "r");
            if (TRB == NULL)
            {
                printf("\nNao foi possivel abrir o arquivo\n");
            }
            else
            {
                printf("Arquivo aberto com sucesso!");
                bowA = fopen("bowA.txt", "w");
                calculateBow(pDictionary, TRB, pContA, bowA);
                fclose(bowA);

                break;
            }

        case 'B':
            printf("\nArquivo de referência B: ");
            scanf("%s", fileName);

            if (TRB != NULL)
            {
                fclose(TRB);
            }
            TRB = fopen(fileName, "r");
            if (TRB == NULL)
            {
                printf("\nNao foi possivel abrir o arquivo\n");
            }
            else
            {
                printf("Dicionario aberto com sucesso!");
                bowB = fopen("bowB.txt", "w");
                calculateBow(pDictionary, TRB, pContB, bowB);
                fclose(bowB);

                break;
            }
        case 'T':
            //Exibir BOWs de TRA e TRB
            printf("Palavras        Texto A(#)      Texto B(#)");
            printOccurrences(pDictionary, pContA, pContB);
            break;

        case 't':
            printf("\nSimilaridade:");
            printf("\n%.2lf de distancia euclidiana\n", euclidiana(pContA, pContB, wordCounters));
            break;

        case 'S':
            free(pContA);
            free(pContB);

            break;

        default:
            printf("\nOpção inválida!\n");
            break;
        }

    } while (opcao != 'S');

    printf("\n\n ----- Sistema Encerrado ----- \n\n");

    return 0;
}

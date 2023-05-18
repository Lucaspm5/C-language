#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() 
{
    int size;
    scanf("%d", &size);

    int ***matriz = (int ***)calloc(size, sizeof(int **));

    for (int i = 0; i < size; i++) {
        *(matriz + i) = (int **)calloc(size, sizeof(int *));
        for (int j = 0; j < size; j++) {
            *(*(matriz + i) + j) = (int *)calloc(size, sizeof(int));
        }
    }

    double raio = size / 2.0;


    if(matriz != NULL) printf("O raio da maior esfera inscrita na matriz é: %.2f\n", raio);
    else
        printf("Ocorreu algum erro\n");

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++)
            free(*(*(matriz + i) + j));
        free(*(matriz + i));
    }
    free(matriz);

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int **matriz = (int**) malloc(5 * sizeof(int*));

void read(int **matriz){

    srand(time(NULL));

    for(int i = 0;i < 5;i++){
        *(matriz + i) = (int*) malloc(3 * sizeof(int));
    }

    for(int i = 0;i < 5;i++){
        for(int j = 0;j < 3;j++){
            *(*(matriz + i) + j) = rand() % 1000;
        }
    }

}

void imprimir(int **matriz){

    read(matriz);

    for(int i = 0;i < 5;i++){
        for(int j = 0;j < 3;j++){
            printf("%d ",*(*(matriz + i)+j));
        }
        printf("\n");
    }

    desaloca(matriz);
}

void desaloca(int **matriz){

    for(int i = 0;i < 5;i++){
        free(*(matriz + i));
    }

    free(matriz);
}

int main(int argc, char const **argv)
{
    imprimir(matriz);
    return 0;
}

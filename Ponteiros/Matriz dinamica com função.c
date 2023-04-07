#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int read()
{
    int **mat = malloc(12 * sizeof(int*));

    for(int i = 0;i < 12;i++){
        mat[i] = malloc(12 * sizeof(int));
    }

    srand((unsigned)time(NULL));

    for(int i = 0;i < 12;i++){
        for(int j = 0;j < 12;j++){
            mat[i][j] = rand() % 10;
        }
    }
    return mat;
}

void imprimir(int **mat){
    for(int i = 0;i < 12;i++){
        for(int j = 0;j < 12;j++){
            printf("[%d]", mat[i][j]);
        }
        printf("\n");
    }
}

int main(int argc, char **argv){
    int **mat;

    mat = read();
    imprimir(mat);

    // Liberar memória alocada para a matriz
    for(int i = 0;i < 12;i++){
        free(mat[i]);
    }
    free(mat);
    
    return 0;
}

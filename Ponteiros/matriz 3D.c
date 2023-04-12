#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char **argv)
{
    int ***matrix;

    srand((unsigned)time(NULL));

    matrix = (int ***) malloc(3 * sizeof(int **));

    for(int i = 0; i < 3; i++){
        *(matrix + i) = (int **) malloc(3 * sizeof(int *));
        for(int j = 0; j < 3; j++){
            *(*(matrix + i) + j) = (int *) malloc(3 * sizeof(int));
        }
    }

    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            for(int k = 0; k < 3; k++) {
                *(*(*(matrix + i) + j) + k) = rand() % 10;
            }
        }
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                printf("%d ", *(*(*(matrix + i) + j) + k));
            }
            printf("\n");
        }
        printf("\n");
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            free(*(*(matrix + i) + j));
        }
        free(*(matrix + i));
    }
    free(matrix);

    return 0;
}

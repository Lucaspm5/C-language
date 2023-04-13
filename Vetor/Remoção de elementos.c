#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const **argv){

    int size;

    printf("Informe o tamanho do vetor\n");
    scanf("%d", &size);

    int *array = malloc(size * sizeof(int));

    printf("Informe os elementos do vetor\n");

    for(int i = 0; i < size; i++){
        scanf("%d", &*(array + i));
    }

    int quant;

    printf("Quantos elementos deseja excluir\n");
    scanf("%d", &quant);

    printf("Informe os elementos a serem excluidos\n");

    int *array2 = malloc(quant * sizeof(int));
    int sentinela = -1;
    int posicao = -1;

    for(int j = 0; j < quant; j++){
        scanf("%d", &*(array2 + j));
    }

    while(quant--)
    {
        for(int i = 0; i < size; i++){
            for(int j = i + 1; j < size; j++){
                if(*(array2 + quant) == *(array + i)){
                    posicao = i;
                    sentinela = 1;
                    break;
                }
            }
            if(sentinela)
            {
                for(int k = posicao; k < size - 1; k++){
                    *(array + k) = *(array + k + 1);
                }
                *(array + size - 1) = 0;
                size--;
                sentinela = -1;
            }
        }
    }
    printf("Novo vetor\n");

    for(int i = 0; i < size; i++){
        printf("%d ", *(array + i));
    }

    free(array);
    free(array2);

    return 0;
}

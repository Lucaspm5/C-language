#include <stdio.h>
#include <stdlib.h>

int* remover(int *arr, int size, int *flag, int qnt){
    int *novo_valor = (int *)malloc(size * sizeof(int));
    int k = 0;
    for(int i = 0; i < size;i++){
        if(*(arr + i) != *(flag + qnt))
        {
            *(novo_valor + k) = *(arr + i);
            k++;
        }
    }

    return novo_valor;
}

void imprime(int *arr,int size, int qnt){
    for(int i = 0;i < size;i++){
        if(*(arr + i) != 0)
            printf("%d ",*(arr + i));
    }
    printf("\n");
}

void read(int *arr, int size){
    for(int i = 0;i < size;i++){
        scanf("%d" ,&*(arr + i));
    }
}

int main(int argc, char **argv){
    int size;

    printf("Informe o tamanho do vetor:\n");
    scanf("%d", &size);

    int *array = (int*)malloc(size * sizeof(int));

    read(array,size);

    int qnt;

    printf("Informe quantos elementos deseja excluir:\n");
    scanf("%d", &qnt);

    int *flag = (int*)malloc(qnt * sizeof(int));

    printf("Informe valores para excluir:\n");

    for(int j = 0;j < qnt;j++){
        scanf("%d", &*(flag + j));
    }

    int *arr = array;

    while(qnt--){
        arr = remover(arr,size,flag,qnt);
    }
    imprime(arr, size, qnt);

    free(array);
    free(arr);

    return 0;
}
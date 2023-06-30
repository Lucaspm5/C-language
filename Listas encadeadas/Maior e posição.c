#include <stdlib.h>
#include <stdio.h>

typedef struct no {
    int dados;
    struct no *prox;
} NO;

NO *push_back(NO *arr, int num) {
    NO *aux, *new_ptr = (NO*)malloc(sizeof(NO));

    new_ptr->dados = num;
    new_ptr->prox = NULL;

    if (arr == NULL) {  
        arr = new_ptr;
    } else {
        aux = arr;
        while (aux->prox != NULL) aux = aux->prox;
        aux->prox = new_ptr;
    }
    return arr;
}

int maior(NO *arr, int* indice) {
    NO *aux = (NO*)malloc(sizeof(NO));
    aux = arr;
    int cont = 1;
    int maior = arr->dados;
    while (aux != NULL) {
        if (aux->dados > maior) {
            maior = aux->dados;
            *indice = cont;
        }
        aux = aux->prox;
        cont++;
    }
    return maior;
}

int main() {
    NO *arr = NULL;
    int max = 0, indice = 0, valor;
    for (int i = 0; i < 100;i++) {
        scanf("%d", &valor);
        arr = push_back(arr, valor);
    }
    max = maior(arr, &indice);
    printf("%d\n%d\n", max, indice);
    //imprimir(arr);
    return 0;
}
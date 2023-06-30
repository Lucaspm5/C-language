#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int dados;
    struct no *prox;
} NO;

NO *push_back(NO *arr, int n) {
    NO *aux, *new_ptr = (NO*)malloc(sizeof(NO));
    new_ptr->dados = n;
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

NO *fibonacci(int indice) {
    NO *sequencia = NULL;
    sequencia = push_back(sequencia, 0);
    sequencia = push_back(sequencia, 1);
    NO *penultimo = sequencia;
    NO *ultimo = sequencia->prox;
    for (int i = 2;i < indice;i++) {
        int new_value = penultimo->dados + ultimo->dados;
        sequencia = push_back(sequencia, new_value);
        penultimo = ultimo;
        ultimo = ultimo->prox;
    }
    return sequencia;
}

int main() {
    int n;
    NO *aux = NULL;
    scanf("%d", &n);
    aux = fibonacci(n);
    while (aux != NULL) {
        printf("%d", aux->dados);
        if (aux->prox != NULL) {
            printf(" ");
        } else {
            printf("\n");
        }
        aux = aux->prox;
    }
    return 0;
}


#include <stdio.h>

void auxiliary(int* a, int* b)
{
    int aux = *a;
    *a = *b;
    *b = aux;
}

int menor(int* arr, int N)
{
    int indice = 0;

    for (int i = 1;i < N;i++)
    {
        if (*(arr + i) < *(arr + indice)) { indice = i; }
    }

    return indice;
}

void ordena_crescente(int *arr, int N)
{
    if (arr == NULL || arr < 1 || N == 1) return 0;

    else{
        int indice = menor(arr, N);

        auxiliary(&*(arr + 0), &*(arr + indice));

        ordena_crescente(arr + 1, N - 1);
    }
}

int main()
{
    int N;

    scanf("%d", &N);

    int arr[N];

    for (int i = 0;i < N;i++) scanf("%d", &arr[i]);

    ordena_crescente(arr, N);

    for (int i = 0;i < N;i++) printf("%d ", *(arr + i));

    return 0;
}
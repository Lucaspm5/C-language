#include <stdio.h>

void trocar(int *a, int *b)
{
    int aux = *a;
    *a = *b;
    *b = aux;
}

void inverter(int *inicio, int *fim)
{
    if (inicio >= fim || inicio == NULL || fim == NULL) return 0;

    else{
        trocar(inicio, fim);
        inverter(inicio + 1, fim - 1);
    }
}
int main()
{
    int size;

    scanf("%d", &size);

    int arr[size];

    for (int i = 0;i < size;i++) scanf("%d", &arr[i]);

    inverter(arr, arr + size - 1);

    for (int i = 0;i < size;i++) printf("%d ",arr[i]);

    return 0;
}
#include <stdio.h>

int somar_vetor(int *arr, int N)
{
    if (arr == NULL || N == 0) return 0;

    else return  arr[0] + somar_vetor(arr + 1, N - 1);
}

int main()
{
    int N;

    scanf("%d", &N);

    int arr[N];

    for (int i = 0;i < N;i++)
        scanf("%d", &arr[i]);

    int result = somar_vetor(arr, N);

    printf("%d\n", result);

    return 0;
}
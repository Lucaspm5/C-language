#include <stdio.h>

int somar_vetor(int *arr, int N)
{
    return (arr == NULL || N == 0) ? 0 : arr[0] + somar_vetor(arr + 1, N - 1);
}

int main()
{
    int N;

    scanf("%d", &N);

    int arr[N];

    for (int i = 0;i < N;i++) scanf("%d", &arr[i]);

    int result = somar_vetor(arr, N);

    printf("%d\n", result);

    return 0;
}

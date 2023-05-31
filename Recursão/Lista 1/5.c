#include <stdio.h>

int somar(int n)
{
    return (n < 1) ? 0 : n + somar(n-1);
}

int main()
{
    int N, aux = 0;

    scanf("%d", &N);

    printf("%d\n", somar(N));

    return 0;
}

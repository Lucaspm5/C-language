#include <stdio.h>

int somar(int n)
{
    if (n < 1) return 0;
    
    return n + somar(n - 1);
}

int main()
{
    int N, aux = 0;

    scanf("%d", &N);

    printf("%d\n", somar(N));

    return 0;
}
#include <stdio.h>

// Fibonacci com programação dinâmica
#define MAX 100
#define validar -1

int sequencia[MAX];

void inicializar()
{
    for (int i = 0;i < MAX;i++) sequencia[i] = validar;
}

int fibonacci_sequence(int n)
{
    if (sequencia[n] == validar)
    {
        if (n <= 1) return sequencia[n] = n;
        else
            sequencia[n] = fibonacci_sequence(n - 1) + fibonacci_sequence(n - 2);
    }
    return sequencia[n];
}

int main()
{
    int k;

    scanf("%d", &k);

    inicializar();

    printf("%d\n", fibonacci_sequence(k));

    return 0;
}
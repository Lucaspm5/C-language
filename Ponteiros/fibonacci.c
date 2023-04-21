#include <stdio.h>

void fibonacci(int *fib,int n)
{
    for(int i = 2; i < n; i++)
    {
        *(fib + i) = *(fib + i - 1) + *(fib + i - 2);
    }
}

int main(int argc, char const **argv)
{
    int i, n = 20;

    int *fib = (int*)malloc(n * sizeof(int));

    *(fib + 0) = 0;
    *(fib + 1) = 1;

    fibonacci(fib,20);

    printf("Sequencia de Fibonacci:\n");
    for(i = 0; i < n; i++)
    {
        printf("%d ", *(fib + i));
    }

    free(fib);

    return 0;
}

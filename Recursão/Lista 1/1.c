#include <stdio.h>

int fatorial(int n)
{
    return (n == 0 || n == 1) ? 1 : n * fatorial (n - 1);
}

int main()
{

    int fat;

    scanf("%d", &fat);

    printf("%d! = %d" , fat, fatorial(fat));

    return 0;
}

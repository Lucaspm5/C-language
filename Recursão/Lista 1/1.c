#include <stdio.h>

int fatorial(int n)
{
    if (n == 0 || n == 1) return 1;

    else return n * fatorial(n - 1);
}

int main(){

    int fat;

    scanf("%d", &fat);

    printf("%d! = %d" , fat, fatorial(fat));

    return 0;
}
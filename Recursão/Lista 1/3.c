#include <stdio.h>

int inverter(int n)
{
    if (n <= 9) return n;

    else
    {
        printf("%d", n % 10); 
        inverter(n / 10);
    }
}

int main(){

    int seq;

    scanf("%d", &seq);

    printf("%d\n", inverter(seq));

    return 0;
}
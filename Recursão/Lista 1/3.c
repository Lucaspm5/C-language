#include <stdio.h>

int inverter(int n)
{
    return (n <= 9) ? n : (printf("%d", n % 10), inverter (n / 10));
}

int main(){

    int seq;

    scanf("%d", &seq);

    printf("%d\n", inverter(seq));

    return 0;
}

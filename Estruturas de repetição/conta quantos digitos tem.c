#include <stdio.h>

int conta_digitos(int x)
{
    int cont = 0;

    while(x != 0){
        //int digit = x % 10;
        x/= 10;
        cont++;
    }

    return cont;
}

int main(int argc, char const **argv){

    int x;

    scanf("%d", &x);

    int flag = conta_digitos(x);

    printf("%d",flag);

    return 0;
}
#include <stdio.h>

int soma_digitos(int x)
{
    int soma = 0;

    // caso o x chege a valer 0, o loop é encerrado
    while(x != 0)
    {
        soma += x % 10;// adiciona o ultimo elemento de x a soma
        x /= 10;// corta o ultimo digito, pois nesse caso é um numero (int)
    }

    return soma;
}

int main(int argc, char const **argv)
{
    int num;

    scanf("%d", &num);

    int aux = soma_digitos(num);

    printf("%d\n",aux);

    return 0;
}
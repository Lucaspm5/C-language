#include <stdio.h>

int soma_digitos_validos(int x)
{
    while(x > 9)//ira ocorrer enquanto estiver mais de um digito
    {
        int soma = 0;//a cada loop a soma devera ser incrementada a zero, pois é o X nesse caso que define o loop
        while(x != 0)
        {
            soma += x % 10;//atribui o ultimo digito de x a soma
            x /= 10;//exclui o ultimo elemento do x
        }
        x = soma;//a soma sera atribuida ao x
    }
    return x;
}

int main(int argc, char const **argv){

    int nums;

    scanf("%d",&nums);

    int aux = soma_digitos_validos(nums);

    printf("%d\n",aux);

    return 0;
}
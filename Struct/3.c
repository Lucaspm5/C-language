#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int x,y;
}Ponto;

//-----------------------------------------------------------
// Estou utilizando um ponteiro para a estrutura, pois é uma alternativa mais eficiente
void captura(Ponto *p)
{
    // Acesso o campo de X e de Y, para alterar seus valores
    scanf("%d %d",&p->x, &p->y);
}
//-----------------------------------------------------------
void imprimir(Ponto *p)
{
    printf("%d - %d\n",p->x,p->y);
}
//-----------------------------------------------------------
int main()
{
    Ponto p;

    // Estou passando como paramentro o endereço da minha variavel p
    captura(&p);
    imprimir(&p);

    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char nome[50];
    int dia, mes, ano;
}Contato;
////////////////////////////////////////////////
void imprimir(Contato **c, int quant);
int cadastro(Contato **c, int quant, int size);
////////////////////////////////////////////////
int main(void)
{
    Contato *agenda[50];//Guarda endereço para contatos

    int tam = 50,cont = 0;

    imprimir(agenda, cont);

    while(cont < tam)
    {
        cont += cadastro(agenda, cont, tam);
        printf("Quantidade de cadastros: %d\n",cont);
        imprimir(agenda, cont);
    }
    return 0;
}
////////////////////////////////////////////////
void imprimir(Contato **c, int quant)
{
    printf("\nLista de contatos\n");
    printf("---------------------\n");
    for(int i = 0; i < quant;i++)
    {
        printf("%d --> %2d/%2d/%4d - %s",i+1,c[i]->dia,c[i]->mes,c[i]->ano,c[i]->nome);
    }
    printf("---------------------\n");
}
////////////////////////////////////////////////
int cadastro(Contato **c, int quant, int size)
{
    if(quant < size)
    {
        Contato *novo = malloc(sizeof(Contato));//aloca de maneira dinamica,só é liberada ao fim do arquivo é diferente se fosse apenas novo
        printf("Digite o nome do contato: \n");
        fgets(novo->nome,50,stdin);
        printf("Informe a data: dd mm aa: \n");
        scanf("%d %d %d",&novo->dia,&novo->mes,&novo->ano);
        fflush(stdin);
        c[quant] = novo;
        return 1;//retorno com sucesso
    }else{
        printf("ERROR: Vetor cheio!\n");
        return 0;//retorno com falha
    }
}

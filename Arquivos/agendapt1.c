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
void alterar_cadastro(Contato **c, int quant);
////////////////////////////////////////////////
int main(void)
{
    Contato *agenda[50];//Guarda endereço para contatos

    int tam = 50, cont = 0, opcao = 0;

    do
    {
        printf("1 - Cadastrar 2 - Imprimir 3 - Alterar Cadastro 4 - Sair\n");
        scanf("%d",&opcao);
        switch(opcao)
        {
            case 1:
                cont += cadastro(agenda, cont, tam);
                break;
            case 2:
                imprimir(agenda,cont);
                break;
            case 3:
                alterar_cadastro(agenda,cont);
                break;
            case 4:
                break;
            default:
                printf("Opcao invalida!\n");
        }
    }while(opcao != 4);
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
        fflush(stdin);
        fgets(novo->nome,50,stdin);
        printf("Informe a data: dd mm aa: \n");
        scanf("%d %d %d",&novo->dia,&novo->mes,&novo->ano);
        c[quant] = novo;
        return 1;//retorno com sucesso
    }else{
        printf("ERROR: Vetor cheio!\n");
        return 0;//retorno com falha
    }
}
////////////////////////////////////////////////
void alterar_cadastro(Contato **c, int quant)
{
    int aux;

    imprimir(c, quant);

    printf("Informe o indice do contato que deseja alterar:\n");
    scanf("%d",&aux);
    aux--;//pois os indices estao sendo somados la em cima

    if(aux >= 0 && aux < quant)//codigo valido
    {
        Contato *novo = malloc(sizeof(Contato));
        printf("Digite o nome do contato: \n");
        fflush(stdin);
        fgets(novo->nome,50,stdin);
        printf("Informe a data: dd mm aa: \n");
        scanf("%d %d %d",&novo->dia,&novo->mes,&novo->ano);
        c[aux] = novo;
    }else{
        printf("Codigo invalido!\n");
    }
}

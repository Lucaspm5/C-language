#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char nome[50];
    int idade;
    char sexo;
}Pessoa;
//////////////////////////////////////////////////
int tam = 10;
Pessoa lista[10];
int cont = 0;
//////////////////////////////////////////////////
int cadastrar();
void imprimir();
void salvararquivos();
void lerarquivos();
//////////////////////////////////////////////////
int main(void)
{
    int op;

    do
    {
        printf("1 - Cadastrar 2 - Imprimir 3 - Salvar em arquivos  4 - Ler em arquivos 0 - Sair\n");
        scanf("%d",&op);

        switch(op)
        {
            case 0:
                break;
            case 1:
                cadastrar();
                break;
            case 2:
                imprimir();
                break;
            case 3:
                salvararquivos();
                break;
            case 4:
                lerarquivos();
                break;
            default:
                printf("Opcao invalida.\n");
        }
    }while(op != 0);

    return 0;
}
//////////////////////////////////////////////////
int cadastrar()
{
    if(cont < tam)
    {
        Pessoa p;
        scanf("%*c");
        printf("Nome: ");
        fflush(stdin);
        fgets(p.nome,50,stdin);
        printf("Digite idade e sexo m ou f: ");
        scanf("%d %c",&p.idade,&p.sexo);
        lista[cont] = p;
        cont++;
        return 1;
    }else{
        printf("ERRO: Vetor cheio.\n");
        return 0;
    }
}
//////////////////////////////////////////////////
void imprimir()
{
    for(int i = 0; i < cont;i++)
    {
        printf("Nome: %s",lista[i].nome);
        printf("Idade: %d\nSexo: %c\n",lista[i].idade,lista[i].sexo);
    }
}
//////////////////////////////////////////////////
void salvararquivos()
{
    FILE *arq = fopen("lista.txt","w");

    if(arq)
    {
        fprintf(arq,"%d\n",cont);

        for(int i = 0;i < cont;i++)
        {
            fprintf(arq," %s ",lista[i].nome);
            fprintf(arq," %d\n",lista[i].idade);
            fprintf(arq," %c\n",lista[i].sexo);
        }
        fclose(arq);
    }else{
        printf("ERRO - ao abrir o arquivo!\n");
    }
}
//////////////////////////////////////////////////
void lerarquivos()
{
    FILE *arq = fopen("lista.txt","r");

    if(arq)
    {
        fscanf(arq, "%d\n", &cont);

        for(int i = 0;i < cont;i++)
        {
            Pessoa p;
            fgets(p.nome,50,arq);
            fscanf(arq,"%d\n",&p.idade);
            fscanf(arq,"%d\n",&p.sexo);
            lista[i] = p;
        }
        fclose(arq);
    }else{
        printf("ERRO - ao abrir o arquivo!\n");
    }
}

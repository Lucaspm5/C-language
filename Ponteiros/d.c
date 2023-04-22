#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *verificaposicao(char str[], int *ptr_cont)
{
    char restricao[] = {"!' '&%$#@*.,;:^~`{]+=|/"};
    int size = strlen(str);
    int cont = 0;
    char *auxiliary = (char*)malloc(size + 1 * sizeof(char));

    for(int i = 0;i < size;i++)
    {
        if(!strchr(restricao,str[i]))
        {
            auxiliary[cont++] = str[i];
            printf("%c",str[i]);
        }
    }

    auxiliary[cont] = '\0';

    //tecnica para retornar mais de um valor, &cont esta sendo modificada na main
    *ptr_cont = cont;
    //retornando o ponteiro cont
    return auxiliary;
}

void inverte(char auxiliary[],int cont)
{
    printf("\n");
    // i devese ser iniciado de acordo com o cont - 1
    for(int i = cont - 1; i >= 0;i--)
        printf("%c",auxiliary[i]);
    // Liberando memoria alocada
    free(auxiliary);
}

int main(int argc, char const **argv)
{
    int cont = 0;
    char str[100];

    scanf("%[^\n]s", str);
    // int *aux é criado pois um ponteiro sera retornado
    // &cont passando o endereço de memoria para a funcao para que essa o conteudo dessa variavel seja alterado
    int *aux = verificaposicao(str, &cont);
    // o cont aqui ja esta valendo um outro valor e podera entrar na proxima função
    inverte(aux, cont);
    return 0;
}
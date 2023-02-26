#include <stdio.h>

char letra;
////////////////////////////////
void escrever(char *f);
void ler(char *f);
////////////////////////////////
int main(void)
{
    char nome[] = {"Conto.txt"};

    escrever(nome);
    ler(nome);

    return 0;
}
////////////////////////////////
void escrever(char *f)
{
    FILE *arq = fopen(f,"w");


    if(arq)
    {
        printf("Digite um texto e prescione ENTER\n");
        scanf("%c",&letra);

        while(letra != '\n')
        {
            fputc(letra,arq);
            scanf("%c",&letra);
        }
        fclose(arq);
    }else{
        printf("ERRO!\n");
    }
}
////////////////////////////////
void ler(char *f)
{
    FILE *arq = fopen(f,"r");

    if(arq)
    {
        printf("Texto lido do arquivo:\n");
        while(!feof(arq))//Enquanto o arquivo n chegar ao fim, o operador '!' sendo usado para negar a afirmação
        {
            letra = fgetc(arq);//serve para ser uma letra
            printf("%c",letra);//imprimi ate chegar o fim
        }
        fclose(arq);
    }else{
        printf("ERRO!\n");
    }
}
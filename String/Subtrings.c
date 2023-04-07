#include <stdio.h>
#include <string.h>

#define size 1000

void imprimir(const char *str, int inicio, int fim, int tam){

    if(fim < tam)
    {
        for(int i = inicio;i < fim;i++){
            printf("%c",*(str + i));
        }
        printf(" ");
        imprimir(str,inicio, fim + 1, tam);
    }else if(inicio < fim)
    {
        imprimir(str, inicio + 1, inicio + 1,tam);
    }

}
int main(int argc, char **argv){

    char str[size ];

    fgets(str,size,stdin);

    int tam = strlen(str);

    imprimir(str, 0, 0, tam);

    return 0;
}
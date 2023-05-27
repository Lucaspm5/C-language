#include <stdio.h>
#include <string.h>

int main()
{
    char procurado[30];
    // Crio um array bidmensional de 10 elementos, os nomes não estão diretamente ligado com os números
    // Tanto o nome quanto os números são strings, cada uma será acessada diante de um indice
    char conteudo[10][30] = {
        "Joao","111-333" ,
        "Lucas","222-444" ,
        "Gabriel","333-555" ,
        "Fernando","444-555" ,
        "jotinha", "555-666"
    };
    // entro com um nome que desejo procurar
    scanf("%s", procurado);
    // Percorro todos os 10 elementos e soma + 2 para que a proxima comparação também seja feita com um nome
    for (int i = 0;i < 10;i+=2)
    {
        /*Se o procurado for igual a um elemento array, eu printo conteudo[i+1], assim invez de imprimir o proprio nome encontrado,
        eu encontro o número em sequência*/
        if (!strcmp(procurado, conteudo[i]))
            printf("%s",conteudo[i+1]);
    }

    return 0;
}
/*Caso eu queria printar apenas os nomes
for (int i = 0;i < 10;i+=2) printf("%s\n",conteudo[i]);
i = 0, vai ser "Joao"
i = 1, vai ser "111-333"
i = 2, vai ser "Lucas"
i = 3, vai ser "222-444"

i += 2 garante que o proximo seja um nome, 0 + 2 = 2, ou seja, a saida sera Lucas
*/
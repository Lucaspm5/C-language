#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *remove_char(char *string, char caractere){

    char *nova_string = (char*)malloc(100 * sizeof(char));
    int j = 0;

    for(int i = 0;i < strlen(string); i++){
        if (string[i] != caractere) {
            nova_string[j] = string[i];
            j++;
        }
    }

    nova_string[j] = '\0';

    free(string);

    return nova_string;
}
int main() {
    char caractere;
    char *string = (char*)malloc(100 * sizeof(char*));

    printf("Digite uma string: ");
    fgets(string,100,stdin);

    printf("Digite o caractere que deseja remover: ");
    scanf("%c", &caractere);

    char *auxiliary = remove_char(string, caractere);

    printf("A nova string é: %s", auxiliary);

    free(auxiliary);

    return 0;
}

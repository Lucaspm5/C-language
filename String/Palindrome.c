#include <stdio.h>
#include <string.h>

int main(int argc, char **argv){
    char str[100];

    fgets(str, 100, stdin);
    str[strcspn(str, "\n")] = '\0'; // remova o caractere \n, se presente
    int size = strlen(str);
    int auxiliary = 1;

    for(int i = 0, j = size - 1; i < j;i++, j--){
        if(str[i] != str[j])
        {
            auxiliary = 0;
            break;
        }
    }

    if(auxiliary){
        printf("%s eh um palindromo.\n", str);
    }else{
        printf("%s nao eh um palindromo.\n", str);
    }
    return 0;
}

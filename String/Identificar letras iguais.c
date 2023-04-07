#include <stdio.h>
#include <string.h>

int main(int argc, char **argv)
{
    char str[100];
    int cont = 0;
    char flag[100];

    fgets(str, 100, stdin);
    str[strcspn(str, "\n")] = '\0';

    int size = strlen(str);

    for(int i = 0;i < size;i++){
        for(int j = i + 1;j < size;j++){
            if(str[i] == str[j])
            {
                cont++;
                flag[cont-1] = str[j];
            }   
        }
    }

    printf("%d\n",cont);

    for(int i = 0;i < cont;i++){
        printf("%c", flag[i]);
    }
}

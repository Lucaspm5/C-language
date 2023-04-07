#include <stdio.h>

int main() {
    int casos;
    printf("Digite o número de linhas: ");
    scanf("%d", &casos);

    for(int i = 0; i < casos; i++) {
        for(int j = 0; j < casos - i - 1; j++) {
            printf(" ");
        }
        for(int j = 0; j < 2 * i + 1; j++) {
            printf("*");
        }
        printf("\n");
    }
    return 0;
}

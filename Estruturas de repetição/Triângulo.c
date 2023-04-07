#include <stdio.h>

int main(int argc, char **argv) {
    int casos;
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

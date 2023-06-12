#include <stdio.h>

int soma_sucessiva(int n1, int n2) {
    return (n2 == 0) ? 0 : n1 + soma_sucessiva(n1, n2 - 1);
}

int main() {
    int n1 = 6, n2 = 3;
    //8
    printf("%d\n", soma_sucessiva(n1, n2));
    return 0;
}
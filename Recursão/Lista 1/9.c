#include <stdio.h>

int contar_frequencia(int n, int k, int cont) {
    if (n < 1) return cont;
    return (n % 10 == k) ?  contar_frequencia(n/10, k, cont + 1) : contar_frequencia(n/10, k, cont);
}

int main() {
    int n = 1112345, k = 1;
    printf("%d\n", contar_frequencia(n, k, 0));
    return 0;
}
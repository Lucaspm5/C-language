#include <stdio.h>

void decrescente(int n) {
    return (n + 1 == 0) ? 0 : (printf("%d ", n), decrescente(n-1));
}

int main() {
    int n = 10;
    decrescente(n);
    return 0;
}
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int fatorial(int n, int* auxiliary, bool* calculado) {
    if (calculado[n]) return auxiliary[n];
    if (n == 1) return 1;
    else {
        return auxiliary[n] = n * fatorial(n - 1, auxiliary, calculado);
    }
    calculado[n] = true;
    return auxiliary[n];
}

int main() {
    int n = 5;
    int auxiliary[n+1];
    bool calculado[n+1];
    memset(calculado, false, sizeof(calculado));

    printf("%d\n", fatorial(n, auxiliary, calculado));
}

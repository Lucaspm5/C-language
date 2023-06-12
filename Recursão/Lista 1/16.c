#include <stdio.h>

int fatorial(int n) {
    return (n <= 1) ? 1 : n * fatorial(n - 1);
}

int main() {
    int n = 3;
    int l = fatorial(n*2) / fatorial(n);
    printf("%d\n", l);
    return 0;
}
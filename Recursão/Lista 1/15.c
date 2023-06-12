#include <stdio.h>

int fatorial(int n) {
    if (n == 0) return 1;
    return (n % 2 != 0) ? n * fatorial(n-1) : fatorial(n - 1);
}

int main() {
    int n = 4;
    printf("%d\n", fatorial(n));
    return 0;
}
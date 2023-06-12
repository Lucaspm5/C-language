#include <stdio.h>
#include <math.h>

int fatorial(int n) {
    return (n <= 1) ? 1 : pow(n, n) * fatorial(n - 1);
}

int main() {
    int n = 3;
    printf("%d\n", fatorial(n));
    return 0;
}
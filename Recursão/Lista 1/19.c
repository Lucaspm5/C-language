#include <stdio.h>
#include <math.h>

long long fatorial(int n) {
    return (n <= 1) ? 1 : pow(n, fatorial(n-1));
}

int main() {
    int n = 3;
    printf("%lld\n", fatorial(n));
    return 0;
}
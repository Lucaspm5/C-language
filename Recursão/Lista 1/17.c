#include <stdio.h>

long long fatorial(int n) {
    return (n <= 1) ? 1 : n * fatorial(n-1);
}

long long super_fatorial(int n) {
    return (n <= 1) ? 1 : fatorial(n) * super_fatorial(n - 1);
}

int main() {
    int n = 4;
    printf("%lld\n", super_fatorial(n));

    return 0;
}
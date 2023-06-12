#include <stdio.h>

void ordem(int n) {
    if (n + 1 == 0) return;
    return (n % 2 == 0) ? (printf("%d ", n), ordem(n-1)) : ordem(n-1);
}

int main() {
    int n = 10;
    ordem(n);
    return 0;
}
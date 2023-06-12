#include <stdio.h>

void ordem(int n, int auxiliary) {
    return (auxiliary-1 == n) ? 1 : (printf("%d ", auxiliary), ordem(n, auxiliary+1));
}

int main() {
    int n = 10;
    ordem(n, 0);
    return 0;
}
#include <stdio.h>

void inverter(int* arr, int size) {
    return (size < 1) ? 1 : ( printf("%d", arr[size-1]), inverter(arr, size - 1));
}

int main() {
    int arr[] = {5, 4, 3, 2, 1};

    inverter(arr, 5);
    return 0;
}

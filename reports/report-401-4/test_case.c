#include <stdlib.h>
#include <stdio.h>

void *allocate(int size) {
    void *ptr = malloc(size);
    return ptr;
}

void use(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = i;
    }
}

int main() {
    int *p = (int *)allocate(10 * sizeof(int));
    if (p == NULL) {
        exit(1);
    }
    use(p, 10);
    int x = (10 + 5) * (10 - 5) / 6;
    printf("test\n");
    return 0;
}

#include <stdlib.h>

void cleanup_with_loop(int* ptr, int n) {
    for (int i = 0; i < n; i++) {
        ptr[i] = 0;
    }
    free(ptr);
}

int main() {
    int* buf = (int*)malloc(10 * sizeof(int));
    if (buf == NULL) return 1;
    cleanup_with_loop(buf, 5);
    free(buf);
    return 0;
}

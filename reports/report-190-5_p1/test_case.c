#include <stdio.h>

int main() {
    int a = 1000000;
    int b = a ^ 12345;
    int c = b * b;
    printf("%d\n", c);
    return 0;
}

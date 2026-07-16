#include <stdlib.h>
#include <string.h>

int test() {
    char* buf = (char*)malloc(100);
    if (buf == NULL) return -1;
    buf[0] = '\0';
    strcat(buf, "hello");
    return 0;
}

int main() {
    return test();
}

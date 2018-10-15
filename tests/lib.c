#include <stdio.h>
#include <string.h>

extern "C" {
    int scan(char *data, size_t size) {
        for(size_t i = 0; i < size; i ++) {
            putchar(*data);
            data += 1;
        }
        printf("\n");
        return 0xdeadbeef;
    }
}

int main(void) {
    char hoge[] = "hello world";
    char *fuga = hoge;

    scan(fuga, strlen(hoge));
}



#include <stdio.h>

extern "C" {
    int scan(void) {
        puts("hello world");
        return 0xdeadbeef;
    }
}

int main(void) {
    scan();
}



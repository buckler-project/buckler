#include <stdio.h>
#include <string.h>


extern "C" {
    bool scan(unsigned char *data, size_t size) {
        printf("\nsize: %d\n", (int)size);
        printf("---data---\n");

        for(size_t i = 0; i < size; i ++) {
            printf("%c: %d\n", *data, *data);
            data += 1;
        }
        printf("\n");
        return true;
    }
}


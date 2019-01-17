#include <stdio.h>
#include <string.h>


extern "C" {
    bool scan(unsigned char *target, size_t target_size, unsigned char *signature, size_t signature_size) {
        printf("\nsize: %d\n", (int)target_size);
        printf("--- target ---\n");

        for(size_t i = 0; i < target_size; i ++) {
            printf("%c: %d\n", *target, *target);
            target += 1;
        }
        printf("\n");

        printf("\nsize: %d\n", (int)target_size);
        printf("--- signature ---\n");
        for(size_t i = 0; i < signature_size; i ++) {
            printf("%c: %d\n", *signature, *signature);
            target += 1;
        }
        printf("\n");

        return true;
    }
}


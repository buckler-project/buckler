#include <stdio.h>
#include <string.h>
#include <stdlib.h>

extern "C" {
    bool scan(unsigned char *target, size_t target_size, unsigned char *signature, size_t signature_size) {
        char *_target = (char *)malloc((target_size + 1) * sizeof(unsigned char));
        char *_signature = (char *)malloc((signature_size + 1) * sizeof(unsigned char)); 
        
        memcpy(_target, target, target_size);
        memcpy(_signature, signature, signature_size);
        
        *(_target + target_size) = 0x00;
        *(_signature + signature_size) = 0x00;

        bool result = strcmp(_target, _signature) == 0;
        
        printf("target:\n%s\n\n", _target);
        printf("signature:\n%s\n\n", _signature);
        printf("result:\n%d\n\n", result);

        free(_target);
        free(_signature);
        return result;
    }
}



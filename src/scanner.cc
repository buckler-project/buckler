#include <string>
#include <iostream>

#include <dlfcn.h> 

#include "base.cc"
#include "signature.cc"

#pragma once


class Scanner {
public:
    std::string path;
    void *handler = NULL;

    Scanner(const std::string _path) {
        path = _path;
    }

    bool Scan(Signature signature) {
        handler = dlopen(path.c_str(), RTLD_LAZY);

        if (!handler) {
            std::cerr << dlerror() << std::endl;
            handler = NULL;
        }

        int (*scan)(unsigned char *, size_t) = (int (*)(unsigned char *, size_t))dlsym(handler, "scan");
    
        char *error_msg = dlerror();
        if (error_msg) {
            std::cerr << error_msg << std::endl;
            
            dlclose(handler);
            handler = NULL;
        }

        unsigned char *ptr = signature.buffer.data();
        size_t size = signature.buffer.size();
        bool result = (*scan)(ptr, size);
        
        dlclose(handler);

        return result;
    }
};


class ScannerController : IteratableObject<Scanner> {
public:
    void Build(const std::string path) {
        Scanner scanner = Scanner(path);
        Add(scanner);
    }
};

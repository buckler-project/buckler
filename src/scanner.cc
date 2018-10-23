#include <string>
#include <iostream>

#include <dlfcn.h> 

#include "base.cc"
#include "signature.cc"

#pragma once

#define SCANNER_LIST "./tests/data/scanner/scanner.list"


class Scanner {
public:
    Target target;
    std::string path;
    void *handler = NULL;

    Scanner() {}

    Scanner(Target _target, const std::string _path) {
        path = _path;
        target = _target;
    }

    bool Scan(Signature signature) {
        handler = dlopen(path.c_str(), RTLD_LAZY);

        if (!handler) {
            std::cerr << dlerror() << std::endl;
            handler = NULL;
        }

        int (*scan)(unsigned char *, size_t, unsigned char *, size_t) = 
            (int (*)(unsigned char *, size_t, unsigned char *, size_t))dlsym(handler, "scan");
    
        char *error_msg = dlerror();
        if (error_msg) {
            std::cerr << error_msg << std::endl;
            
            dlclose(handler);
            handler = NULL;
        }

        unsigned char *target_ptr = target.buffer.data();
        size_t target_size = target.buffer.size();
        unsigned char *signature_ptr = signature.buffer.data();
        size_t signature_size = signature.buffer.size();
        bool result = (*scan)(target_ptr, target_size, signature_ptr, signature_size);
        
        dlclose(handler);

        return result;
    }
};


class ScannerRepository : public IteratableObject<Scanner>{};


class ScannerController {
public:
    Target target;
    ScannerRepository repository = ScannerRepository();

    ScannerController() {}

    ScannerController(Target _target) {
        target = _target;
        AddFromFiles(SCANNER_LIST);
    }
    
    void AddFromPath(const std::string path) {
        Scanner scanner = Scanner(target, path);
        repository.Add(scanner);
    }

    void AddFromFiles(const std::string path) {
        std::ifstream ifs(path);
        std::string line;
        
        if (ifs.fail()) {
            std::cerr << "failed to open file" << std::endl;
        }

        while (getline(ifs, line)) {
            AddFromPath(line);
        }

        ifs.close();
    }
};
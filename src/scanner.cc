#include <string>
#include <iostream>

#include <dlfcn.h> 

#include "base.cc"
#include "signature.cc"

#pragma once

#define SCANNER_LIST "./tests/data/scanner.list"


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


class ScannerRepository : public IteratableObject<Scanner>{};


class ScannerController : IteratableObject<Scanner> {
public:
    ScannerRepository repository = ScannerRepository();

    ScannerController() {
        AddFromFiles(SCANNER_LIST);
    }

    void AddFromPath(const std::string path) {
        Scanner scanner = Scanner(path);
        repository.Add(scanner);
    }

    void AddFromFiles(const std::string path) {
        std::ifstream ifs(path);
        std::string line;
        
        if (ifs.fail()) {
            std::cerr << "failed to open file" << std::endl;
        }

        while (getline(ifs, line)) {
            std::cout << "[" << line << "]" << std::endl;
            AddFromPath(line);
        }

        ifs.close();
    }
};

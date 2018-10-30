#include <string>
#include <iostream>

#include <dlfcn.h> 

#include "base.hpp"
#include "signature.hpp"

#pragma once

#define SCANNER_LIST "./tests/data/scanner/scanner.list"


namespace Buckler {
class Scanner {
public:
    Target target;
    std::string path;
    void *handler = NULL;

    Scanner();

    Scanner(Target _target, const std::string _path);

    bool Scan(Signature signature);
};


class ScannerRepository : public IteratableObject<Scanner>{};


class ScannerController {
public:
    Target target;
    ScannerRepository repository = ScannerRepository();

    ScannerController();

    ScannerController(Target _target);
    
    void AddFromPath(const std::string path);

    void AddFromFiles(const std::string path);
};
}

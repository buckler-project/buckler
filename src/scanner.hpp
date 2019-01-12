#include <string>
#include <iostream>

#include <dlfcn.h> 

#include "base.hpp"
#include "signature.hpp"

#pragma once

#define SCANNER_LIST ".scanners/"


namespace buckler {
class Scanner {
public:
    Target target;
    std::string path;
    void *handler = NULL;

    Scanner();

    Scanner(Target _target, const std::string _path);

    bool Scan(Signature signature);
};


class ScannerList : public IteratableObject<Scanner>{};


class ScannerController {
public:
    Target target;
    ScannerList list = ScannerList();

    ScannerController();

    ScannerController(Target _target);
    
    void AddFromPath(const std::string path);

    void AddFromFiles(const std::string path);
};
}

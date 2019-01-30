#include <string>
#include <iostream>

#include <dlfcn.h> 

#include "base.hpp"
#include "signature.hpp"

#pragma once

#define SCANNER_TYPE "scanner"
#define SCANNER_DIRECTORY ".scanners/"
#define SCANNER_CONFIG "scanner.yml"

namespace buckler {
class Scanner {
public:
    std::string path;
    std::string loadable_file;
    void *handler = NULL;

    Scanner();

    Scanner(const std::string path);

    bool ScanOne(Target target, std::vector<unsigned char> signature);

    Result Scan(Target target, Signature signature);

};

class ScannersList : public IteratableObject<Scanner> {};

class ScannersRepository : public Repository<Scanner> {
public:
    ScannersRepository(ScannersList *list);

    Scanner Load(YAML::Node config, std::string path);
};

class ScannerController {
public:
    Target target;
    ScannersList list = ScannersList();
    ScannersRepository repository = ScannersRepository(&list);

    ScannerController();
    ScannerController(Target target);

    void Load();
};
}

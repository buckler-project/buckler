#pragma once

#include "base.hpp"
#include "signature.hpp"
#include "scanner.hpp"
#include "update.hpp"


namespace buckler {
class Buckler {
public:
    Target target;
    Result result;

    ScannerController scanners;
    SignaturesController signatures;

    Buckler();
    Buckler(Target target);
    
    void Load();

    Result Scan();
};
}

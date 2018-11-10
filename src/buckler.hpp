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
    RepositoryUpdator repo;

    ScannerController scanners;
    SignatureController signatures;

    Buckler();
    Buckler(Target _target);
    
    void SetUp(Target _target);

    Result Scan();
};
}

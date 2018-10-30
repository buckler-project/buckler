#pragma once

#include "base.hpp"
#include "signature.hpp"
#include "scanner.hpp"
#include "utils.hpp"
#include "update.hpp"


namespace Buckler {
class Buckler {
public:
    Target target;
    Result result;
    RepositoryUpdator repo;

    ScannerController scanners;
    SignatureController signatures;

    Buckler(Target _target);

    Result Scan();
};
}
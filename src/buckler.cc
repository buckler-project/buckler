#include "base.cc"
#include "signature.cc"
#include "scanner.cc"
#include "utils.cc"

#pragma once


class Buckler {
public:
    Target target;
    Result result;

    ScannerController scanners;
    SignatureController signatures;

    Buckler(Target _target) {
        target = _target;
        result = Result();

        signatures = SignatureController();
        scanners = ScannerController(target);
    }

    Result Scan() {
        return result;
    }
};


int main() {
    IteratableObject<std::string> iterator = IteratableObject<std::string>();
    iterator.Add(std::string("hello"));
    iterator.Add(std::string("world"));
    iterator.Add(std::string("!"));

    iterator.Start();
    while(iterator.is_continue) {
        std::string msg = iterator.Next();
        std::cout << msg << std::endl;
    }
}

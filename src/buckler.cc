#include "base.cc"
#include "signature.cc"
#include "scanner.cc"

#pragma once


class Buckler {
public:
    Target target;
    Result result;

    SignatureController signatures;
    ScannerController scanners;

    Buckler(Target _target) {
        target = _target;
        result = Result();

        signatures = SignatureController();
        scanners = ScannerController();
    }

    Result Scan() {
        return result;
    }
};


int main() {
    ScannerController scanner = ScannerController();

    /*
    Signature signature = Signature(std::string("./tests/data/hoge.txt"));
    Scanner scanner = Scanner(std::string("./tests/lib/lib.so"));
    scanner.Scan(signature);
    */
}

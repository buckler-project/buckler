#include "base.cc"
#include "signature.cc"
#include "scanner.cc"

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
    Target target = Target();
    //Buckler buckler = Buckler(target);
    //buckler.Scan();

    ScannerController controller;// = ScannerController(target);

    /*
    Signature signature = Signature(std::string("./tests/data/hoge.txt"));
    Scanner scanner = Scanner(std::string("./tests/lib/lib.so"));
    scanner.Scan(signature);
    */

}

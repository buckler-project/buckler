#include <vector>
#include <string>
#include <iostream>


class Target {
public:
    std::vector<unsigned char> buffer;
};


class Result {
public:
   bool result;
};


class Signature {
public:
    std::vector<unsigned char> buffer;
};


class Scanner {
public:
    Scanner() {}
    bool Scan() {
        return true;
    }
};


class Base {
public:
    Target target;
    Result result;

    std::vector<Signature> signatures;
    std::vector<Scanner> scanners;

    Base(Target _target) {
        target = _target;
        result = Result();
    }

    Result Scan() {
        return result;
    }
};


int main() {
    Target target = Target();
    Base base = Base(target);
    Result result = base.Scan();
}

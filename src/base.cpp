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
    std::string path;
    std::vector<unsigned char> buffer;
    
    Signature(const std::string _path) {
        path = _path;
    }

    bool Scan() {
        return true;
    }
};


class Scanner {
public:
    std::string path;
    Scanner(const std::string _path) {
        path = _path;
    }
    bool Scan(Signature signature) {
        return true;
    }
};


class SignatureRepository {
    std::vector<Signature> signatures;
    
    void Build(const std::string path) {
        Signature signature = Signature(path);
        signatures.push_back(signature);
    }
};


class ScannerRepository {
    std::vector<Scanner> scanners;

    void Build(const std::string path) {
        Scanner scanner = Scanner(path);
        scanners.push_back(scanner);
    }
};


class Base {
public:
    Target target;
    Result result;

    SignatureRepository signatures;
    ScannerRepository scanners;

    Base(Target _target) {
        target = _target;
        result = Result();

        signatures = SignatureRepository();
        scanners = ScannerRepository();
    }

    Result Scan() {
        return result;
    }
};


int main() {
    std::string path("hogehoge");
    Target target = Target();
    Base base = Base(target);
    Result result = base.Scan();
}

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


template <typename T>
class ObjectIterator {
public:
    std::vector<T> objects;
    typename std::vector<T>::iterator itr;
    bool has_finished = true;

    void Start() {
        itr = objects.begin();
        has_finished = false;
    }
    
    T End() {
        return (T)0;
    }

    Signature Next() {
        if (has_finished) {
            return End();
        }

        if (itr == objects.end()) {
            has_finished = true;
        }

        return *itr;
    }

    void Add(T object) {
        objects.push_back(object);
    }

};


class SignatureController : ObjectIterator<Signature> {
public:
    void Build(const std::string path) {
        Signature signature = Signature(path);
        Add(signature);
    }
};


class ScannerController : ObjectIterator<Scanner> {
public:
    void Build(const std::string path) {
        Scanner scanner = Scanner(path);
        Add(scanner);
    }
};


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
    std::string path("hogehoge");
    Target target = Target();
    Buckler buckler = Buckler(target);
    Result result = buckler.Scan();
}

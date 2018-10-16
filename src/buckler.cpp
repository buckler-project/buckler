#include <vector>
#include <string>
#include <iostream>
#include <fstream>

#include <dlfcn.h> 
#include <stdio.h>


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
        std::fstream fs;

        fs.open(path, std::ios::in | std::ios::binary);
        char data;

        if (fs.fail()) {
            std::cerr << "failed to open file\n" << std::endl;
            return;
        }

        while(!fs.eof()){
            fs.read(&data, sizeof(unsigned char));
            buffer.push_back(data);
        }

        fs.close();
    }
};


class Scanner {
public:
    std::string path;
    void *handler = NULL;

    Scanner(const std::string _path) {
        path = _path;
    }

    bool Scan(Signature signature) {
        handler = dlopen(path.c_str(), RTLD_LAZY);

        if (!handler) {
            std::cerr << dlerror() << std::endl;
            handler = NULL;
        }

        int (*scan)(unsigned char *, size_t) = (int (*)(unsigned char *, size_t))dlsym(handler, "scan");
    
        char *error_msg = dlerror();
        if (error_msg) {
            std::cerr << error_msg << std::endl;
            
            dlclose(handler);
            handler = NULL;
        }

        unsigned char *ptr = signature.buffer.data();
        size_t size = signature.buffer.size();
        bool result = (*scan)(ptr, size);
        
        dlclose(handler);

        return result;
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
    Signature signature = Signature(std::string("./tests/hoge.txt"));
    Scanner scanner = Scanner(std::string("./tests/libfunc.so"));
    bool hoge = scanner.Scan(signature);
    //std::cout << hoge << std::endl;
}

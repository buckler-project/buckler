#pragma once

#include <vector>
#include <map>
#include <algorithm>


namespace buckler {
class Target {
public:
    std::vector<unsigned char> buffer;

    Target();

    Target(std::vector<unsigned char> buffer);

    Target(unsigned char* ptr, size_t size);
};

class Log {
public:
    std::string scanner;
    std::string signature;
    std::string signature_file;

    Log() {}
    Log(std::string scanner, std::string signature, std::string signature_file)
        : scanner(scanner), signature(signature), signature_file(signature_file) {}
};

class Result {
public:
   bool has_hit = false;
   std::vector<Log> hits = {};

   Result();
   void Include(Result result);
};
}

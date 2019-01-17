#pragma once

#include <vector>
#include <map>
#include <algorithm>


namespace buckler {
class Target {
public:
    std::vector<unsigned char> buffer;

    Target();

    Target(std::vector<unsigned char> _buffer);

    Target(unsigned char* ptr, size_t size);

    void SetBuffer(std::vector<unsigned char> _buffer);

    void SetBuffer(unsigned char* ptr, size_t size);
};


class Result {
public:
   bool is_hit;
   std::map<std::string, std::string> hits;

   Result();
};
}

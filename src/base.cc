#include <vector>
#include <map>
#include <algorithm>

#pragma once


namespace Buckler {
class Target {
public:
    std::vector<unsigned char> buffer;

    Target() {}

    Target(std::vector<unsigned char> _buffer) {
        size_t size = _buffer.size();
        buffer.resize(size);
        std::copy(_buffer.begin(), _buffer.end(), buffer.begin());
    }

    Target(unsigned char* ptr, size_t size) {
        for(size_t i = 0; i < size; i ++) {
            unsigned char data = *(ptr + i);
            buffer.push_back(data);
        }
    }
};


class Result {
public:
   bool is_hit;
   std::map<std::string, std::string> hits;

   Result() {
       is_hit = false;
   }
};
}

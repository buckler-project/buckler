#include "base.hpp"

namespace buckler {

Target::Target() {};

Target::Target(std::vector<unsigned char> buffer) : buffer(buffer) {}

Target::Target(unsigned char* ptr, size_t size) {
    for(size_t i = 0; i < size; i ++) {
        unsigned char data = *(ptr + i);
        buffer.push_back(data);
    }
}

Result::Result() {}
}

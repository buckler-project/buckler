#include "base.hpp"

namespace buckler {

Target::Target() {};

Target::Target(std::vector<unsigned char> buffer) {
    SetBuffer(buffer);
}

Target::Target(unsigned char* ptr, size_t size) {
    SetBuffer(ptr, size);
}

void Target::SetBuffer(std::vector<unsigned char> _buffer) {
    size_t size = _buffer.size();
    buffer.resize(size);
    std::copy(buffer.begin(), buffer.end(), buffer.begin());
}

void Target::SetBuffer(unsigned char* ptr, size_t size) {
    for(size_t i = 0; i < size; i ++) {
        unsigned char data = *(ptr + i);
        buffer.push_back(data);
    }
}

Result::Result() {
    is_hit = false;
}
}

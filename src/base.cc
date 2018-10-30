#include "base.hpp"

namespace Buckler {

Target::Target() {};

Target::Target(std::vector<unsigned char> _buffer) {
    size_t size = _buffer.size();
    buffer.resize(size);
    std::copy(_buffer.begin(), _buffer.end(), buffer.begin());
}

Target::Target(unsigned char* ptr, size_t size) {
    for(size_t i = 0; i < size; i ++) {
        unsigned char data = *(ptr + i);
        buffer.push_back(data);
    }
}

Result::Result() {
    is_hit = false;
}
}
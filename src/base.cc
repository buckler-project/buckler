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

Result::Result() {
}

void Result::Include(Result result) {
    has_hit = has_hit | result.has_hit;
    hits.insert(hits.end(), result.hits.begin(), result.hits.end());
}
}

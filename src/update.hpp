#pragma once

#include <boost/process.hpp>
#include <boost/algorithm/string/replace.hpp>

#define SIGNATURE_PATH "./tests/data/signature/"


namespace buckler {
class RepositoryUpdator {
private:
    std::string cmd;

public:
    RepositoryUpdator ();

    void Update();
};
}

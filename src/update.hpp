#pragma once

#include <boost/process.hpp>
#include <boost/algorithm/string/replace.hpp>

#define SIGNATURE_PATH "./tests/data/signature/"


namespace Buckler {
class RepositoryUpdator {
private:
    std::string cmd;

public:
    RepositoryUpdator ();

    void Update();
};
}

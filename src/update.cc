#include <boost/process.hpp>
#include <boost/algorithm/string/replace.hpp>

#pragma once
#define SIGNATURE_PATH "./tests/data/signature/"


namespace Buckler {
class RepositoryUpdator {
private:
    std::string cmd;

public:
    RepositoryUpdator () {
        cmd = std::string("bash -c \"{}\"");
        boost::algorithm::replace_all(cmd, "{}", "cd {} && git submodule foreach git pull origin master");
        boost::algorithm::replace_all(cmd, "{}", SIGNATURE_PATH);
    }

    void Update() {
        boost::process::child child(cmd);
        child.wait();
    }
};
}

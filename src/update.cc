#include "update.hpp"

namespace Buckler {

RepositoryUpdator::RepositoryUpdator () {
    cmd = std::string("bash -c \"{}\"");
    boost::algorithm::replace_all(cmd, "{}", "cd {} && git submodule foreach git pull origin master");
    boost::algorithm::replace_all(cmd, "{}", SIGNATURE_PATH);
}

void RepositoryUpdator::Update() {
    boost::process::child child(cmd);
    child.wait();
}
}
#include "signature.hpp"


namespace buckler {
Signature::Signature(const std::string _path) {
    path = _path;
    std::fstream fs;

    fs.open(path, std::ios::in | std::ios::binary);
    char data;

    if (fs.fail()) {
        std::cerr << "failed to open file\n" << std::endl;
        return;
    }

    while(!fs.eof()){
        fs.read(&data, sizeof(unsigned char));
        buffer.push_back(data);
    }

    fs.close();
}


SignatureController::SignatureController() {
    AddFromDefaultDirectory();
}

void SignatureController::AddFromPath(const std::string path) {
    Signature signature = Signature(path);
    repository.Add(signature);
}

void SignatureController::AddFromDirectory(const std::string path) {
    namespace fs = boost::filesystem;

    fs::recursive_directory_iterator last;
    for (fs::recursive_directory_iterator itr(path); itr != last; ++itr ) {
        AddFromPath(itr -> path().string());
    }
}

void SignatureController::AddFromDefaultDirectory() {
    AddFromDirectory(SIGNATURE_DIRECTORY);
}
}

#include "signature.hpp"
#include <vector>



namespace buckler {

Signature::Signature(std::string path) : path(path) {}

SignaturesRepository::SignaturesRepository(SignaturesList *list) : Repository(list) {
    parent_path = std::string(SIGNATURE_DIRECTORY);
    config_name = std::string(SIGNATURE_CONFIG);
}

Signature SignaturesRepository::Load(YAML::Node config, std::string path) {
    Signature signature = Signature(path);
    
    namespace fs = boost::filesystem;
    fs::recursive_directory_iterator last;
    
    for (fs::recursive_directory_iterator itr(path); itr != last; ++itr) {
        if (itr -> path().filename().string() == config_name) continue;
        
        signature.path_list.Add(itr -> path().string());
    }
    return signature;
}    

std::vector<unsigned char> Signature::GetFileBuffer(std::string path) {
    std::vector<unsigned char> buffer = {};

    std::fstream fs;

    fs.open(path, std::ios::in | std::ios::binary);
    char data;

    if (fs.fail()) {
        std::cerr << "failed to open file\n" << std::endl;
        return {};
    }

    while(!fs.eof()){
        fs.read(&data, sizeof(unsigned char));
        buffer.push_back(data);
    }
    buffer.pop_back();

    fs.close();

    return buffer;
}

SignaturesController::SignaturesController() {
    list = SignaturesList();
    repository = SignaturesRepository(&list);
}

void SignaturesController::Load() {
    repository.LoadAll();
}
}

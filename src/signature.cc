#include "signature.hpp"
#include <vector>



namespace buckler {

Signature::Signature(std::string path) : path(path) {}

SignaturesRepository::SignaturesRepository(SignaturesList *list) : Repository(list) {
    type = SIGNATURE_TYPE;
    config_path = SIGNATURE_CONFIG;
    parent_path = SIGNATURE_DIRECTORY;
}

Signature SignaturesRepository::Load(YAML::Node config, std::string name, std::string path) {
    Signature signature = Signature(path);
    
    signature.name = name;    
    signature.support_scanner = config["scanner"].as<std::string>();
    signature.data_path = config["data"].as<std::string>();

    namespace fs = boost::filesystem;
    fs::recursive_directory_iterator last;
    
    for (fs::recursive_directory_iterator itr(path + "/" + signature.data_path); itr != last; ++itr) {
        if (itr -> path().filename().string() == config_path) continue;
        
        std::cout << path << std::endl;
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

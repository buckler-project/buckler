#include "scanner.hpp"
#include <dlfcn.h> 


namespace buckler {
Scanner::Scanner() {}

Scanner::Scanner(const std::string path) : path(path) {}

bool Scanner::ScanOne(Target target, std::vector<unsigned char> signature) {
    handler = dlopen(loadable_file.c_str(), RTLD_LAZY);

    if (!handler) {
        std::cerr << dlerror() << std::endl;
        handler = NULL;
    }

    int (*scan)(unsigned char *, size_t, unsigned char *, size_t) = 
        (int (*)(unsigned char *, size_t, unsigned char *, size_t))dlsym(handler, "scan");

    char *error_msg = dlerror();
    if (error_msg) {
        std::cerr << error_msg << std::endl;
        
        dlclose(handler);
        handler = NULL;
    }

    unsigned char *target_ptr = target.buffer.data();
    size_t target_size = target.buffer.size();
    unsigned char *signature_ptr = signature.data();
    size_t signature_size = signature.size();
    bool result = (*scan)(target_ptr, target_size, signature_ptr, signature_size);
    
    dlclose(handler);

    return result;
}

Result Scanner::Scan(Target target, Signature signature) {
    Result result = Result();
    
    namespace fs = boost::filesystem;
    fs::recursive_directory_iterator last;

    signature.path_list.Start();
    while(signature.path_list.is_continue) {
        std::string path = signature.path_list.Next();
        std::vector<unsigned char> signature_buf = signature.GetFileBuffer(path);
        bool has_hit = ScanOne(target, signature_buf);

        if(has_hit) {
            result.has_hit = true;
            Log log = Log(this->path, signature.path, path);
            result.hits.push_back(log);
        }
    }

    return result;
}

ScannersRepository::ScannersRepository(ScannersList *list) : Repository(list) {
    parent_path = std::string(SCANNER_DIRECTORY);
    config_name = std::string(SCANNER_CONFIG);
}

Scanner ScannersRepository::Load(YAML::Node config, std::string path) {
    Scanner scanner = Scanner(path);
    scanner.loadable_file = scanner.path + "/" + config["loadable"].as<std::string>();

    return scanner;
}

ScannerController::ScannerController() {}

ScannerController::ScannerController(Target target) : target(target) {}

void ScannerController::Load() {
    repository.LoadAll();
}
}

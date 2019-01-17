#pragma once

#include <iostream>
#include <fstream>

#include <boost/filesystem.hpp>
#include "yaml-cpp/yaml.h"


#include "utils.cc"


#define SIGNATURE_DIRECTORY ".signatures/"
#define SIGNATURE_CONFIG "signature.yml"


namespace buckler {
class Signature {
public:
    std::string path;
    IteratableObject<std::string> path_list = IteratableObject<std::string>();
    
    Signature(const std::string _path);
    
    std::vector<unsigned char> GetBuffer();
};


class SignaturesList : public IteratableObject<Signature> {};

class SignaturesRepository : public Repository<Signature> {
public:
    SignaturesRepository(SignaturesList *list);

    Signature Load(YAML::Node config, std::string path);
};


class SignaturesController {
public:
    SignaturesList list = SignaturesList();
    SignaturesRepository repository = SignaturesRepository(&list);

    SignaturesController();
};
}

#pragma once

#include <iostream>
#include <fstream>

#include <boost/filesystem.hpp>
#include "yaml-cpp/yaml.h"


#include "utils.cc"


#define SIGNATURE_TYPE "signature"
#define SIGNATURE_DIRECTORY ".signatures/"
#define SIGNATURE_CONFIG "signature.yml"


namespace buckler {
class Signature {
public:
    std::string name = "";
    std::string path = "";
    std::string support_scanner = "";
    IteratableObject<std::string> path_list = IteratableObject<std::string>();
    
    Signature(){};
    Signature(std::string path);
    
    std::vector<unsigned char> GetFileBuffer(std::string path);
};


class SignaturesList : public IteratableObject<Signature> {};

class SignaturesRepository : public Repository<Signature> {
public:

    SignaturesRepository() {}
    SignaturesRepository(SignaturesList *list);

    Signature Load(YAML::Node config, std::string name, std::string path);
};


class SignaturesController {
public:
    SignaturesList list;
    SignaturesRepository repository;

    SignaturesController();
    void Load();
};
}

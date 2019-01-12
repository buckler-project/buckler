#pragma once

#include <iostream>
#include <fstream>

#include <boost/filesystem.hpp>
#include "yaml-cpp/yaml.h"


#include "utils.cc"


#define SIGNATURE_DIRECTORY ".signatures/"


namespace buckler {
class Signature {
public:
    std::string path;
    std::vector<unsigned char> buffer;
    
    Signature(const std::string _path);
};


class SignaturesList : public IteratableObject<Signature>{};

class SignatureController {
public:
    SignaturesList list = SignaturesList();

    SignatureController();
    void AddFromPath(const std::string path);

    void AddFromDirectory(const std::string path);

    void AddFromDefaultDirectory();
};
}

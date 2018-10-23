#include <iostream>
#include <fstream>

#include <boost/filesystem.hpp>


#include "utils.cc"

#pragma once

#define SIGNATURE_DIRECTORY "./tests/data/signature/"


class Signature {
public:
    std::string path;
    std::vector<unsigned char> buffer;
    
    Signature(const std::string _path) {
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
};


class SignatureRepository : public IteratableObject<Signature>{};

class SignatureController {
public:
    SignatureRepository repository = SignatureRepository();

    SignatureController() {
        AddFromDefaultDirectory();
    }

    void AddFromPath(const std::string path) {
        Signature signature = Signature(path);
        repository.Add(signature);
    }

    void AddFromDirectory(const std::string path) {
        namespace fs = boost::filesystem;

        fs::recursive_directory_iterator last;
        for (fs::recursive_directory_iterator itr(path); itr != last; ++itr ) {
            AddFromPath(itr -> path().string());
        }
    }

    void AddFromDefaultDirectory() {
        AddFromDirectory(SIGNATURE_DIRECTORY);
    }
};


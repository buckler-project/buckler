#pragma once

#include <vector>
#include <iostream>

#include <boost/filesystem.hpp>
#include <boost/foreach.hpp>
#include <boost/range/iterator_range.hpp>


#include "yaml-cpp/yaml.h"

#define MAIN_CONFIG "./buckler.yml"


namespace buckler {
template <class T>
class IteratableObject {
public:
    std::vector<T> data = {};
    typename std::vector<T>::iterator itr;
    bool is_continue = false;

    IteratableObject() {}
    
    void Start() {
        if (data.size() == 0) {
            is_continue = false;
            return;
        
        } else {
            is_continue = true;
        }

        itr = data.begin();
    }
    
    T Next() {
        if (!is_continue) {
            return *(data.end());
        }

        if (data.size() == 0) {
            std::cerr 
                << "failed to get element from vector " 
                << "(vector has no elements)"
                << std::endl;
            
            return *(data.begin());
        }

        typename std::vector<T>::iterator result = itr;

        itr ++;

        if(itr == data.end()) {
            is_continue = false;
        }

        return *result;
    }

    void Add(T object) {
        data.push_back(object);
    }
};


template <class T>
class Repository {
public:
    std::string type;
    std::string parent_path;
    std::string config_path;
    IteratableObject<T> *list;

    Repository() {}

    Repository(IteratableObject<T> *list) {
        this -> list = list;
    }

    Repository(IteratableObject<T> *list, std::string parent_path) {
        this -> list = list;
        this -> parent_path = parent_path;
    }

    virtual T Load(YAML::Node config, std::string path) {
        std::cerr << "[err] not defined load." << std::endl;
        return (T)0;
    }

    void LoadAll(){
        namespace fs = boost::filesystem;

        std::string main_config = MAIN_CONFIG;
        YAML::Node config = YAML::LoadFile("./buckler.yml");

        std::vector<std::string> vec = config[type + "s"].as<std::vector<std::string>>();

        for(auto itr = vec.begin(); itr != vec.end(); ++itr) {
            std::string path = parent_path + "/" + *itr;
            std::string _config_path = path + "/" + config_path;

            YAML::Node config = YAML::LoadFile(_config_path);
            T object = Load(config, path);
            list->Add(object);
        }
    }
};
}


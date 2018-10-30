#pragma once

#include <vector>
#include <iostream>


template <typename T>
class IteratableObject {
public:
    std::vector<T> objects;
    typename std::vector<T>::iterator itr;
    bool is_continue = false;

    IteratableObject() {}

    void Start() {
        itr = objects.begin();
        is_continue = true;
    }
    
    T Next() {        
        if (!is_continue) {
            return *(objects.end());
        }

        if (objects.size() == 0) {
            std::cerr 
                << "failed to get element from vector " 
                << "(vector has no elements)"
                << std::endl;
            
            return *(objects.begin());
        }

        typename std::vector<T>::iterator result = itr;

        itr ++;

        if(itr == objects.end()) {
            is_continue = false;
        }

        return *result;
    }

    void Add(T object) {
        objects.push_back(object);
    }
};

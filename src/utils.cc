#pragma once

#include <vector>
#include <iostream>


template <typename T>
class IteratableObject {
public:
    std::vector<T> data;
    typename std::vector<T>::iterator itr;
    bool is_continue = false;

    IteratableObject() {}

    void Start() {
        itr = data.begin();
        is_continue = true;
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

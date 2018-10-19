#include <vector>

#pragma once


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
            itr = objects.end();
        }

        if (itr == objects.end()) {
            is_continue = false;
        }
        
        typename std::vector<T>::iterator result = itr;
        itr ++;

        return *result;
    }

    void Add(T object) {
        objects.push_back(object);
    }
};


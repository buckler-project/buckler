#include "utils.hpp"

#pragma once

#include <vector>
#include <iostream>


template <typename T>
IteratableObject<T>::IteratableObject() {}

template <typename T>
void IteratableObject<T>::Start() {
    itr = data.begin();
    is_continue = true;
}

template <typename T>
T IteratableObject<T>::Next() {        
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

template <typename T>
void IteratableObject<T>::Add(T object) {
    data.push_back(object);
}

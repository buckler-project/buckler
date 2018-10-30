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

    void Start();
    
    T Next();

    void Add(T object);
};


#include <vector>

#pragma once


template <typename T>
class IteratableObject {
public:
    std::vector<T> objects;
    typename std::vector<T>::iterator itr;
    bool has_finished = true;

    IteratableObject() {}

    void Start() {
        itr = objects.begin();
        has_finished = false;
    }
    
    T End() {
        return (T)0;
    }

    T Next() {
        if (has_finished) {
            return End();
        }

        if (itr == objects.end()) {
            has_finished = true;
        }

        return *itr;
    }

    void Add(T object) {
        objects.push_back(object);
    }
};


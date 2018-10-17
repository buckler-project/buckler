#include <vector>

#pragma once


class Target {
public:
    std::vector<unsigned char> buffer;
};


class Result {
public:
   bool result;
};


template <typename T>
class IteratableObject {
public:
    std::vector<T> objects;
    typename std::vector<T>::iterator itr;
    bool has_finished = true;

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


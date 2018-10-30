#include "utils.hpp"

template <typename T>
inline void IteratableObject<T>::Start() {
    itr = objects.begin();
    is_continue = true;
}

template <typename T>
inline T IteratableObject<T>::Next() {
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

template <typename T>
inline void IteratableObject<T>::Add(T object) {
    objects.push_back(object);
};


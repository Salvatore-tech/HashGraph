//
// Created by saso on 30/01/2022.
//

#include "../api/LinearProbingStrategy.h"

template
class LinearProbingStrategy<int>;

template<typename T>
int LinearProbingStrategy<T>::hashCode(T key) {
    return (key % this->tableSize);
}

template<typename T>
int LinearProbingStrategy<T>::rehash(T key, int iterationNo) {
    return hashCode(key + iterationNo);
}
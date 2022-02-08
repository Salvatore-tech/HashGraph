//
// Created by saso on 30/01/2022.
//

#ifndef HASHGRAPH_DOUBLEHASHINGSTRATEGY_H
#define HASHGRAPH_DOUBLEHASHINGSTRATEGY_H


#include "HashingStrategy.h"


template<typename T>
class DoubleHashingStrategy : public HashingStrategy<T> {
public:
    DoubleHashingStrategy(int tableSize);

    int hashCode(T key) override;

    int rehash(T key, int iterationNo) override;

private:
    int firstHashCode(T key);

    int secondHashCode(T key);

    void setSieve();

    int tableSize;
    int primeNumber;
};


#endif //HASHGRAPH_DOUBLEHASHINGSTRATEGY_H

//
// Created by saso on 30/01/2022.
//

#ifndef HASHGRAPH_LINEARPROBINGSTRATEGY_H
#define HASHGRAPH_LINEARPROBINGSTRATEGY_H

#include "HashingStrategy.h"

template<typename T>
class LinearProbingStrategy : public HashingStrategy<T> {
public:
    explicit LinearProbingStrategy(int tableSize) : HashingStrategy<T>(tableSize) {}

    int hashCode(T key) override;

    int rehash(T key, int iterationNo) override;
};


#endif //HASHGRAPH_LINEARPROBINGSTRATEGY_H

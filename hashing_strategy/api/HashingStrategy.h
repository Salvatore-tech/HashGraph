//
// Created by saso on 30/01/2022.
//

#ifndef HASHGRAPH_HASHINGSTRATEGY_H
#define HASHGRAPH_HASHINGSTRATEGY_H

template<typename T>
class HashingStrategy {
public:
    HashingStrategy(int tableSize) : tableSize(tableSize) {}

    virtual int hashCode(T key) = 0;

    virtual int rehash(T key, int iterationNo) = 0;

    virtual ~HashingStrategy() = default;

protected:
    int tableSize;
};


#endif //HASHGRAPH_HASHINGSTRATEGY_H

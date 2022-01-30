//
// Created by saso on 30/01/2022.
//

#ifndef HASHGRAPH_HASHINGSTRATEGY_H
#define HASHGRAPH_HASHINGSTRATEGY_H

template<typename T>
class HashingStrategy {
public:
    virtual int hashCode(T key) = 0;

    virtual int rehash(T key, int iterationNo) = 0;
};


#endif //HASHGRAPH_HASHINGSTRATEGY_H

//
// Created by saso on 24/01/2022.
//

#ifndef HASHGRAPH_HASHTABLEITERATOR_H
#define HASHGRAPH_HASHTABLEITERATOR_H

#include "HashTable.h"

template<typename T>
class HashTableIterator {
public:
    HashTableIterator(HashTable<T> *hashTable);

    void dfs(T keyOfStartingNode) const;

private:
    HashTable<T> *hashTable;
};


#endif //HASHGRAPH_HASHTABLEITERATOR_H

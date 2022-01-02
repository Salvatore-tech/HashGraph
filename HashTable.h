//
// Created by saso on 01/01/2022.
//

#ifndef HASHGRAPH_HASHTABLE_H
#define HASHGRAPH_HASHTABLE_H


#include <list>
#include <ostream>
#include "Graph/TreeNode.h"

class HashTable {
private:
    TreeNode **table;
    TreeNode *dummy{};
    int capacity;
    int size;

public:
    HashTable(int bucketNo);

    int hashCode(int key) const;

    void insertNode(TreeNode &treeNode);

    TreeNode *deleteNode(int key);

    TreeNode **getByKey(int key);

    TreeNode *operator[](int) const;

    friend std::ostream &operator<<(std::ostream &os, const HashTable &table);
};


#endif //HASHGRAPH_HASHTABLE_H

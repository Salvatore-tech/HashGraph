//
// Created by saso on 01/01/2022.
//

#ifndef HASHGRAPH_HASHTABLE_H
#define HASHGRAPH_HASHTABLE_H


#include <list>
#include <ostream>
#include <map>
#include "Graph/TreeNode.h"

class HashTable {
public:
    HashTable(int bucketNo);

    HashTable(const std::map<int, std::vector<int>> &graphData, int numbersOfNodes);

    int hashCode(int key) const;

    int insertNode(TreeNode *treeNode);

    TreeNode *deleteNode(int key);

    TreeNode **getByKey(int key);

    TreeNode *operator[](int) const;

    friend std::ostream &operator<<(std::ostream &os, const HashTable &table);

private:
    TreeNode **table;
    TreeNode *dummy{};
    int capacity;
    int size;
};


#endif //HASHGRAPH_HASHTABLE_H

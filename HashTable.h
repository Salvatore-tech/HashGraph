//
// Created by saso on 01/01/2022.
//

#ifndef HASHGRAPH_HASHTABLE_H
#define HASHGRAPH_HASHTABLE_H


#include <list>
#include <ostream>
#include <map>
#include "Graph/TreeNode.h"

template<typename T>
class HashTable {
public:
    HashTable(int bucketNo);

    HashTable(const std::map<T, std::vector<T>> &graphData, int numbersOfNodes);

    int hashCode(T key) const;

    int insertNode(TreeNode<T> *treeNode);

    TreeNode<T> *deleteNode(T key);

    TreeNode<T> **getByKey(T key);

    TreeNode<T> *operator[](int) const;

    friend std::ostream &operator<<(std::ostream &os, const HashTable<T> &table) {
        os << "HashTable data: \t" << " capacity: " << table.capacity << " size: " << table.size << std::endl;
        for (int i = 0; i < table.capacity; i++)
            if (table[i] == nullptr)
                os << "[" << i << "]: is empty" << std::endl;
            else {
                os << "[" << i << "]: " << table[i]->getKey() << " has edges towards: ";
                for (auto const &edge: table[i]->getNeighbours())
                    os << edge->getKey() << "\t";
                std::endl(os);
            }
        return os;
    }

private:
    TreeNode<T> **table;
    TreeNode<T> *dummy{};
    int capacity;
    int size;

};


#endif //HASHGRAPH_HASHTABLE_H

//
// Created by saso on 01/01/2022.
//

#include <iostream>
#include <map>
#include "HashTable.h"

HashTable::HashTable(int bucketNo) : capacity{bucketNo} {
    table = new TreeNode *[capacity];
    for (int i = 0; i < capacity; i++)
        table[i] = nullptr;
    size = 0;
}

HashTable::HashTable(const std::map<int, std::vector<int>> &graphData, int numberOfNodes) : HashTable(numberOfNodes) {
    for (auto const&[key, val]: graphData) {
        int index = this->insertNode(new TreeNode(key));
        table[index]->setNeighbours(val);
    }
}

int HashTable::hashCode(int key) const {
    return key % capacity;
}

int HashTable::insertNode(TreeNode *treeNode) {
    int hashIndex = hashCode(treeNode->key);

    // find next free space
    while (table[hashIndex] != nullptr
           && table[hashIndex]->key != treeNode->key
           && table[hashIndex]->key != -1) {
        hashIndex++;
        hashIndex %= capacity;
    }

    size++;
    table[hashIndex] = treeNode;
    return hashIndex;
}

std::ostream &operator<<(std::ostream &os, const HashTable &table) {
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

TreeNode *HashTable::operator[](int index) const {
    if (index >= capacity) {
        std::cout << "Index out of bound" << std::endl;
    }
    return table[index];
}

TreeNode *HashTable::deleteNode(int key) {
    TreeNode **nodeToDelete = getByKey(key);
    if (nodeToDelete != nullptr) {
        TreeNode *temp = *nodeToDelete;
        *nodeToDelete = dummy;
        size--;
        return temp;
    }
    return nullptr;
}

TreeNode **HashTable::getByKey(int key) {
    int hashIndex = hashCode(key);
    int loopCounter = 0;

    while (table[hashIndex] != nullptr) {
        if (loopCounter++ > capacity)
            return nullptr;

        if (table[hashIndex]->key == key)
            return &table[hashIndex];

        hashIndex++;
        hashIndex %= capacity;
    }
    return nullptr;
}





//
// Created by saso on 01/01/2022.
//

#include <iostream>
#include "HashTable.h"

HashTable::HashTable(int bucketNo) : capacity{bucketNo} {
    table = new TreeNode *[capacity];
    for (int i = 0; i < capacity; i++)
        table[i] = nullptr;
    size = 0;
}

int HashTable::hashCode(int key) const {
    return key % capacity;
}

void HashTable::insertNode(TreeNode &treeNode) {
    int hashIndex = hashCode(treeNode.key);

    // find next free space
    while (table[hashIndex] != nullptr
           && table[hashIndex]->key != treeNode.key
           && table[hashIndex]->key != -1) {
        hashIndex++;
        hashIndex %= capacity;
    }
//
//    if (table[hashIndex] == nullptr || table[hashIndex]->key == -1) {
    size++;
    table[hashIndex] = &treeNode;

}

std::ostream &operator<<(std::ostream &os, const HashTable &table) {
    os << "HashTable data: \t" << " capacity: " << table.capacity << " size: " << table.size << std::endl;
    for (int i = 0; i < table.capacity; i++)
        if (table[i] == nullptr)
            os << "[" << i << "]: is empty" << std::endl;
        else
            os << "[" << i << "]: " << table[i]->key << std::endl;
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


//
// Created by saso on 01/01/2022.
//

#include <iostream>
#include <map>
#include "HashTable.h"

template
class HashTable<int>; // Types of values stored into the hash table

template<typename T>
HashTable<T>::HashTable(int bucketNo) : capacity{bucketNo} {
    table = new TreeNode<T> *[capacity];
    for (int i = 0; i < capacity; i++)
        table[i] = nullptr;
    size = 0;
}

template<typename T>
HashTable<T>::HashTable(const std::map<T, std::vector<T>> &graphData, int numberOfNodes) : HashTable(numberOfNodes) {
    for (auto const&[key, val]: graphData) {
        int index = this->insertNode(new TreeNode(key));
        table[index]->setNeighbours(val);
    }
}

template<typename T>
int HashTable<T>::hashCode(T key) const {
    return key % capacity;
}

template<typename T>
int HashTable<T>::insertNode(TreeNode<T> *treeNode) {
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
//template <typename T>
//std::ostream &operator<<(std::ostream &os, const HashTable<T> &table) {
//    os << "HashTable data: \t" << " capacity: " << table.capacity << " size: " << table.size << std::endl;
//    for (int i = 0; i < table.capacity; i++)
//        if (table[i] == nullptr)
//            os << "[" << i << "]: is empty" << std::endl;
//        else {
//            os << "[" << i << "]: " << table[i]->getKey() << " has edges towards: ";
//            for (auto const &edge: table[i]->getNeighbours())
//                os << edge->getKey() << "\t";
//            std::endl(os);
//        }
//    return os;
//}

template<typename T>
TreeNode<T> *HashTable<T>::operator[](int index) const {
    if (index >= capacity) {
        std::cout << "Index out of bound" << std::endl;
    }
    return table[index];
}

template<typename T>
TreeNode<T> *HashTable<T>::deleteNode(T key) {
    TreeNode<T> **nodeToDelete = getByKey(key);
    if (nodeToDelete != nullptr) {
        TreeNode<T> *temp = *nodeToDelete;
        *nodeToDelete = dummy;
        size--;
        return temp;
    }
    return nullptr;
}

template<typename T>
TreeNode<T> **HashTable<T>::getByKey(T key) {
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





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
    table = new GraphNode<T> *[capacity];
    for (int i = 0; i < capacity; i++)
        table[i] = nullptr;
    size = 0;
}

template<typename T>
HashTable<T>::HashTable(const std::map<T, std::vector<T>> &graphData, int numberOfNodes) : HashTable(numberOfNodes) {
    for (auto const&[keyOfTheNode, edgesOfTheNode]: graphData) {
        int index = this->insertNode(new GraphNode(keyOfTheNode));
        table[index]->addEdge(edgesOfTheNode);
    }
}

template<typename T>
int HashTable<T>::hashCode(T key) const {
    return key % capacity;
}

template<typename T>
int HashTable<T>::insertNode(GraphNode<T> *graphNode) {
    int hashIndex = hashCode(graphNode->key);

    // find next free space
    while (table[hashIndex] != nullptr
           && table[hashIndex]->key != graphNode->key
           && table[hashIndex]->key != -1) {
        hashIndex++;
        hashIndex %= capacity;
    }

    size++;
    table[hashIndex] = graphNode;
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
//            for (auto const &edge: table[i]->getEdges())
//                os << edge->getKey() << "\t";
//            std::endl(os);
//        }
//    return os;
//}

template<typename T>
GraphNode<T> *HashTable<T>::operator[](int index) const {
    if (index >= capacity) {
        std::cout << "Index out of bound" << std::endl;
    }
    return table[index];
}

template<typename T>
GraphNode<T> *HashTable<T>::deleteNode(T key) {
    GraphNode<T> **nodeToDelete = getByKey(key);
    if (nodeToDelete != nullptr) {
        GraphNode<T> *temp = *nodeToDelete;
        *nodeToDelete = dummy;
        size--;
        return temp;
    }
    return nullptr;
}

template<typename T>
GraphNode<T> **HashTable<T>::getByKey(T key) {
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





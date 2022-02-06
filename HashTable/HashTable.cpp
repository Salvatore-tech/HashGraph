//
// Created by saso on 01/01/2022.
//

#include <iostream>
#include <map>
#include <stack>
#include "HashTable.h"
#include "hashingStrategy/api/LinearProbingStrategy.h"

template
class HashTable<int>; // Types of values stored into the hash table

template<typename T>
HashTable<T>::HashTable(int bucketNo) : capacity{bucketNo} {
    table = new std::shared_ptr<GraphNode<T>>[bucketNo];
    hashingStrategy = new LinearProbingStrategy<T>(capacity);
    size = 0;
    loadFactor = 0;
}

template<typename T>
HashTable<T>::HashTable(const std::map<T, std::vector<T>> &graphData, int numberOfNodes) : HashTable(numberOfNodes) {
    std::vector<std::shared_ptr<GraphNode<T>>> edgeCache;

    for (auto const&[keyOfTheNode, edgesOfTheNode]: graphData) {
        int index = this->insert(std::make_shared<GraphNode<T>>(keyOfTheNode));
        edgeCache.emplace_back(table[index]);
    }

    int i = 0;
    for (auto const&[keyOfTheNode, edgesOfTheNode]: graphData) {
        for (auto const &edgeKey: edgesOfTheNode) {
            auto ptr = getByKey(edgeKey);
            edgeCache.at(i).get()->addEdge(ptr);
        }
        i++;
    }
}

template<typename T>
void HashTable<T>::insert(T nodeKey) {
    if (insert(std::make_shared<GraphNode<T>>(nodeKey)))
        std::cout << "Added node to the table with key = " << nodeKey << std::endl;
    else
        std::cout << "Could not add the node to the table with key = " << nodeKey << std::endl;
}

template<typename T>
int HashTable<T>::insert(std::shared_ptr<GraphNode<T>> graphNode) {
    int hashIndex = 0;
    if (getByKey(graphNode->key, hashIndex) && loadFactor < 0.70) // Avoid duplicate keys in the table
        return -1;
    size++;
    table[hashIndex] = graphNode;
    loadFactor = (float) size / (float) capacity;
    return hashIndex;
}

template<typename T>
void HashTable<T>::deleteByKey(T key) {
    int index = hashingStrategy->hashCode(key);
    if (table[index].get()) {
        table[index].reset();
        size--;
        loadFactor = (float) size / (float) capacity;
        std::cout << "Node with key " << key << " erased\n";
    } else
        std::cout << "Could not delete node with key " << key << std::endl;
}


template<typename T>
std::shared_ptr<GraphNode<T>> HashTable<T>::getByKey(T key) {
    int hashIndex = hashingStrategy->hashCode(key);
    int iterationNo = 0;

    while (table[hashIndex].get() && table[hashIndex]->key != key)
        hashIndex = hashingStrategy->rehash(key, ++iterationNo);

    return table[hashIndex];
}

template<typename T>
std::shared_ptr<GraphNode<T>> HashTable<T>::getByKey(T key, int &hashIndex) {
    hashIndex = hashingStrategy->hashCode(key);
    int iterationNo = 0;

    while (table[hashIndex].get() && table[hashIndex]->key != key)
        hashIndex = hashingStrategy->rehash(key, ++iterationNo);
    return table[hashIndex];
}

template<typename T>
bool HashTable<T>::findEdge(T sourceNodeKey, T targetNodeKey) {
    auto sourceNode = getByKey(sourceNodeKey);
    if (!sourceNode.get())
        return false;
    return sourceNode->hasEdge(targetNodeKey);
}

template<typename T>
bool HashTable<T>::findEdge(std::shared_ptr<GraphNode<T>> sourceNode, std::shared_ptr<GraphNode<T>> targetNode) {
    return findEdge(sourceNode->key, targetNode->key);
}


template<typename T>
void HashTable<T>::addEdge(T sourceNodeKey, T targetNodeKey) {
    auto sourceNode = getByKey(sourceNodeKey);
    auto targetNode = getByKey(targetNodeKey);
    if (sourceNode.get() && targetNode.get() && !findEdge(sourceNode, targetNode)) {// Avoid duplicate edges
        if (sourceNode->addEdge(targetNode))
            std::cout << "Added edge between " << sourceNodeKey << " --> " << targetNodeKey << std::endl;
    }
    std::cout << "Could not add the edge between " << sourceNodeKey << " --> " << targetNodeKey << std::endl;
}

template<typename T>
void HashTable<T>::removeEdge(T sourceNodeKey, T targetNodeKey) {
    auto sourceNode = getByKey(sourceNodeKey);
    if (!sourceNode.get()) {
        std::cout << "Could not find a node with the given key\n ";
        return;
    }

    auto edgesOfTheSourceNode = sourceNode->getEdgesPtr();
    int initialEdges = edgesOfTheSourceNode->size();

    std::erase_if(*edgesOfTheSourceNode, [&targetNodeKey](auto edge) {
        return edge.lock()->getKey() == targetNodeKey;
    });

    int edgesAfterEraseOperation = edgesOfTheSourceNode->size();
    if (edgesAfterEraseOperation < initialEdges)
        std::cout << "Erased edge from " << sourceNodeKey << " --> " << targetNodeKey << std::endl;
    else
        std::cout << "Could not erase edge from " << sourceNodeKey << " --> " << targetNodeKey << std::endl;
}

template<typename T>
std::shared_ptr<GraphNode<T>> HashTable<T>::operator[](int index) const {
    if (index >= capacity) {
        std::cout << "Index out of bound" << std::endl;
    }
    return table[index];
}

template<typename T>
int HashTable<T>::getSize() const {
    return size;
}

template<typename T>
HashTable<T>::~HashTable() {
    delete hashingStrategy;
    for (int i = 0; i < capacity; i++) {
        table[i].reset();
    }
    delete[] table;
}












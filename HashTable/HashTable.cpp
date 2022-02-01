//
// Created by saso on 01/01/2022.
//

#include <iostream>
#include <map>
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

//template<typename T>
//HashTable<T>::HashTable(const std::map<T, std::vector<T>> &graphData, int numberOfNodes) : HashTable(numberOfNodes) {
//    for (auto const&[keyOfTheNode, edgesOfTheNode]: graphData) {
//        int index = this->insert(new GraphNode(keyOfTheNode));
//        if (index >= 0)
//            table[index]->addEdge(edgesOfTheNode);
//    }
//}

template<typename T>
int HashTable<T>::insert(std::shared_ptr<GraphNode<T>> graphNode) {
    int iterationNo = 0;
    if (getByKey(graphNode->key)) // Avoid duplicate keys in the table
        return -1;

    int hashIndex = hashingStrategy->hashCode(graphNode->key);
    // find next free space
    while (table[hashIndex] != nullptr
           && table[hashIndex]->key != graphNode->key
           && table[hashIndex]->key != -1) {
        hashingStrategy->rehash(graphNode->key, ++iterationNo);
    }
    size++;
    table[hashIndex] = graphNode;
    loadFactor = (float) size / (float) capacity;
    return hashIndex;
}

//template<typename T>
//void HashTable<T>::deleteByKey(T key) {
//    if (auto nodeToDelete = getNodeRefByKey(key); nodeToDelete != nullptr) {
//        free(*nodeToDelete);
//        *nodeToDelete = dummy;
//        size--;
//        loadFactor = (float) size / (float) capacity;
//        std::cout << "Node with key " << key << " erased\n";
//    } else
//        std::cout << "Could not erase node with key " << key << "\n";
//}

template<typename T>
std::shared_ptr<GraphNode<T>> HashTable<T>::getByKey(T key) {
    int hashIndex = hashingStrategy->hashCode(key); // TODO rehash needed?
    int loopCounter = 0;

    while (table[hashIndex] != nullptr) {
        if (loopCounter++ > capacity)
            return {};

        if (table[hashIndex]->key == key)
            return table[hashIndex];

        hashIndex++;
        hashIndex %= capacity;
    }
    return {};
}

//template<typename T>
//GraphNode<T> **HashTable<T>::getNodeRefByKey(T key) {
//    int hashIndex = hashingStrategy->hashCode(key);
//    int loopCounter = 0;
//
//    while (table[hashIndex] != nullptr) {
//        if (loopCounter++ > capacity)
//            return nullptr;
//
//        if (table[hashIndex]->key == key)
//            return &table[hashIndex];
//
//        hashIndex++;
//        hashIndex %= capacity;
//    }
//    return nullptr;
//}

template<typename T>
std::shared_ptr<GraphNode<T>> HashTable<T>::findEdge(T sourceNodeKey, T targetNodeKey) {
    auto sourceNode = getByKey(sourceNodeKey);
    if (!sourceNode.get())
        return nullptr;
    for (auto const &edge: sourceNode->edges)
        if (edge->key == targetNodeKey)
//            return edge; TODO
            return nullptr;
    return nullptr;
}

template<typename T>
std::shared_ptr<GraphNode<T>>
HashTable<T>::findEdge(std::shared_ptr<GraphNode<T>> sourceNode, std::shared_ptr<GraphNode<T>> targetNode) {
    return findEdge(sourceNode->key, targetNode->key);
}


template<typename T>
void HashTable<T>::addEdge(T sourceNodeKey, T targetNodeKey) {
    auto sourceNode = getByKey(sourceNodeKey);
    auto targetNode = getByKey(targetNodeKey);
    if (sourceNode.get() && targetNode.get() && !findEdge(sourceNode, targetNode)) {// Avoid duplicate edges
        if (sourceNode->addEdge(*targetNode))
            std::cout << "Added edge between " << sourceNodeKey << " --> " << targetNodeKey << std::endl;
    }
    std::cout << "Could not add the edge between " << sourceNodeKey << " --> " << targetNodeKey << std::endl;
}

template<typename T>
void HashTable<T>::removeEdge(T sourceNodeKey, T targetNodeKey) {
    auto sourceNode = getByKey(sourceNodeKey);
    auto edgesOfTheSourceNode = sourceNode->getEdges(); // TODO
    int initialEdges = edgesOfTheSourceNode.size();

    std::erase_if(edgesOfTheSourceNode, [&targetNodeKey](GraphNode<T> *edge) { return edge->key == targetNodeKey; });

    int edgesAfterEraseOperation = edgesOfTheSourceNode.size();

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









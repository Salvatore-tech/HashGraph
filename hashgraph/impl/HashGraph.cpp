//
// Created by saso on 01/01/2022.
//

#include <iostream>
#include <map>
#include <stack>
#include <assert.h>
#include <cstring>

#include "../api/HashGraph.h"
#include "LinearProbingStrategy.h"
#include "DoubleHashingStrategy.h"

template
class HashGraph<int>; // Types of values stored into the hash table

template<typename T>
HashGraph<T>::HashGraph(int capacity) : capacity{capacity} {
    table.resize(capacity);
    size = 0;
    loadFactor = 0;
}

template<typename T>
void HashGraph<T>::fillTable(const std::map<T, std::vector<T>> &graphData) {
    std::vector<std::shared_ptr<GraphNode<T>>> nodeCache;
    nodeCache.reserve(graphData.size());

    for (auto const&[keyOfTheNode, edgesOfTheNode]: graphData) {
        int index = insert(std::make_shared<GraphNode<T>>(keyOfTheNode));
        if (index >= 0)
            nodeCache.emplace_back(table[index]);
        else
            std::cerr << "Error when reading from graph buffer\n";
    }
    assert(nodeCache.size() == graphData.size());
    int i = 0;
    for (auto const&[keyOfTheNode, edgesOfTheNode]: graphData) {
        for (auto const &edgeKey: edgesOfTheNode) {
            auto ptr = getByKey(edgeKey);
            nodeCache.at(i).get()->addEdge(ptr);
        }
        i++;
    }
}

template<typename T>
void HashGraph<T>::setHashingStrategy(char *strategy) {
    if (strategy == nullptr || strcmp("linear", strategy) == 0) {
        hashingStrategy = new LinearProbingStrategy<T>(capacity);
        std::cout << "Using a linear probing hashing strategy" << std::endl;
    } else {
        hashingStrategy = new DoubleHashingStrategy<T>(capacity);
        std::cout << "Using a double hashing strategy" << std::endl;
    }
}

template<typename T>
void HashGraph<T>::insert(T nodeKey) {
    if (insert(std::make_shared<GraphNode<T>>(nodeKey)))
        std::cout << "Added node to the table with key = " << nodeKey << std::endl;
    else
        std::cout << "Could not add the node to the table with key = " << nodeKey << std::endl;
}

template<typename T>
int HashGraph<T>::insert(std::shared_ptr<GraphNode<T>> graphNode) {
    int hashIndex = 0;
    if (getByKey(graphNode->getKey(), hashIndex) && loadFactor < max_load_factor) // Avoid duplicate keys in the table
        return -1;
    size++;
    table[hashIndex] = graphNode;
    loadFactor = (float) size / (float) capacity;
    return hashIndex;
}

template<typename T>
void HashGraph<T>::deleteByKey(T key) {
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
std::shared_ptr<GraphNode<T>> HashGraph<T>::getByKey(T key) const {
    int hashIndex = hashingStrategy->hashCode(key);
    int iterationNo = 0;

    while (table[hashIndex].get() && table[hashIndex]->getKey() != key)
        hashIndex = hashingStrategy->rehash(key, ++iterationNo);

    return table[hashIndex];
}

template<typename T>
std::shared_ptr<GraphNode<T>> HashGraph<T>::getByKey(T key, int &hashIndex) {
    hashIndex = hashingStrategy->hashCode(key);
    int iterationNo = 0;

    while (table[hashIndex].get() && table[hashIndex]->getKey() != key)
        hashIndex = hashingStrategy->rehash(key, ++iterationNo);
    return table[hashIndex];
}

template<typename T>
bool HashGraph<T>::findEdge(T sourceNodeKey, T targetNodeKey) {
    auto sourceNode = getByKey(sourceNodeKey);
    if (!sourceNode.get())
        return false;
    return sourceNode->hasEdge(targetNodeKey);
}

template<typename T>
bool HashGraph<T>::findEdge(std::shared_ptr<GraphNode<T>> sourceNode, std::shared_ptr<GraphNode<T>> targetNode) {
    return findEdge(sourceNode->getKey(), targetNode->getKey());
}


template<typename T>
void HashGraph<T>::addEdge(T sourceNodeKey, T targetNodeKey) {
    auto sourceNode = getByKey(sourceNodeKey);
    auto targetNode = getByKey(targetNodeKey);
    if (sourceNode.get() && targetNode.get() && !findEdge(sourceNode, targetNode)) {// Avoid duplicate edges
        if (sourceNode->addEdge(targetNode))
            std::cout << "Added edge between " << sourceNodeKey << " --> " << targetNodeKey << std::endl;
    } else
        std::cout << "Could not add the edge between " << sourceNodeKey << " --> " << targetNodeKey << std::endl;
}

template<typename T>
void HashGraph<T>::removeEdge(T sourceNodeKey, T targetNodeKey) {
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
std::shared_ptr<GraphNode<T>> HashGraph<T>::operator[](int index) const {
    if (index >= capacity) {
        std::cout << "Index out of bound" << std::endl;
    }
    return table[index];
}

template<typename T>
HashGraph<T>::~HashGraph() {
    delete hashingStrategy;
    for (int i = 0; i < capacity; i++) {
        table[i].reset();
    }
    table.clear();
}


template<typename T>
void HashGraph<T>::dfs(T keyOfStartingNode) const {
    std::vector<bool> visited(size, false);
    std::stack<std::shared_ptr<GraphNode<T>>> stack;
    auto startingNode = getByKey(keyOfStartingNode);

    if (!startingNode) {
        std::cout << "The key inserted is invalid, could not perform the DFS\n";
        return;
    }

    stack.push(startingNode);
    while (!stack.empty()) {
        auto currentGraphNode = stack.top();
        stack.pop();
        if (!visited[currentGraphNode->getKey()]) {
            std::cout << currentGraphNode->getKey() << " ";
            visited[currentGraphNode->getKey()] = true;
        }
        for (const auto &edge: currentGraphNode->getEdges())
            if (const auto observe = edge.lock()) {
                if (!visited[observe->getKey()])
                    stack.push(observe);
            }
    }
}












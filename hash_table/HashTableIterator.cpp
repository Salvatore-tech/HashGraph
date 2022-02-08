//
// Created by saso on 24/01/2022.
//

#include <stack>
#include <iostream>
#include "HashTableIterator.h"


template
class HashTableIterator<int>;

template<typename T>
HashTableIterator<T>::HashTableIterator(HashTable<T> &hashTable):hashTable(hashTable) {}

template<typename T>
void HashTableIterator<T>::dfs(T keyOfStartingNode) const {
    std::vector<bool> visited(hashTable.getSize() + 1, false);
    std::stack<std::shared_ptr<GraphNode<T>>> stack;
    auto startingNode = hashTable.getByKey(keyOfStartingNode);

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

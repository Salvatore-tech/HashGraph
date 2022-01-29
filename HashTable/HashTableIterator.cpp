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
    std::stack<GraphNode<T> *> stack;
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
        for (auto const &edge: currentGraphNode->getEdges())
            if (!visited[edge->getKey()])
                stack.push(edge);
    }
}

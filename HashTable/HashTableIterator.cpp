//
// Created by saso on 24/01/2022.
//

#include <stack>
#include <iostream>
#include "HashTableIterator.h"


template
class HashTableIterator<int>;

template<typename T>
HashTableIterator<T>::HashTableIterator(HashTable<T> *hashTable):hashTable(hashTable) {}

template<typename T>
void HashTableIterator<T>::dfs(T keyOfStartingNode) const {
    std::vector<bool> visited(hashTable->getSize() + 1, false);
    std::stack<GraphNode<T> *> stack;

    stack.push(hashTable->getByKey(keyOfStartingNode));

    while (!stack.empty()) {
        // Pop a vertex from stack and print it
        GraphNode<T> *currentGraphNode = stack.top();
        stack.pop();

        // Stack may contain same vertex twice. So
        // we need to print the popped item only
        // if it is not visited.
        if (!visited[currentGraphNode->getKey()]) {
            std::cout << currentGraphNode->getKey() << " ";
            visited[currentGraphNode->getKey()] = true;
        }

        // Get all adjacent vertices of the popped vertex currentGraphNode
        // If a adjacent has not been visited, then push it
        // to the stack.

        for (auto const &edge: currentGraphNode->getEdges())
            if (!visited[edge->getKey()])
                stack.push(edge);
    }


//// Initially mark all vertices as not visited
//    std::vector<bool> visited(adjList.size() + 1, false);
//    std::stack<int> stack;
//
//    // Push the current source node.
//    stack.push(adjList.at(sourceIdx).key);
//

}

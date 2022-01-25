//
// Created by saso on 01/01/2022.
//

#ifndef HASHGRAPH_HASHTABLE_H
#define HASHGRAPH_HASHTABLE_H


#include <list>
#include <ostream>
#include <map>
#include "../Graph/GraphNode.h"

template<typename T>
class HashTable {
public:
    HashTable(int bucketNo);

    HashTable(const std::map<T, std::vector<T>> &graphData, int numbersOfNodes);

    int hashCode(T key) const;

    int insertNode(GraphNode<T> *graphNode);

    GraphNode<T> *deleteNode(T key);

    GraphNode<T> *getByKey(T key);

    GraphNode<T> *findEdge(GraphNode<T> *sourceNode, T key);

    GraphNode<T> *findEdge(GraphNode<T> *sourceNode, GraphNode<T> *targetNode);

    void addEdge(GraphNode<T> *sourceNode, GraphNode<T> *targetNode);

    void addEdge(T sourceNodeKey, T targetNodeKey);

    int getSize() const;

    GraphNode<T> *operator[](int) const;

    friend std::ostream &operator<<(std::ostream &os, const HashTable<T> &table) { // TODO: SIGSEGV
        os << "HashTable data: \t" << " capacity: " << table.capacity << " size: " << table.size << std::endl;
        for (int i = 0; i < table.capacity; i++)
            if (table[i] == nullptr)
                os << "[" << i << "]: is empty" << std::endl;
            else if (table[i]->getEdges().empty()) { // The node has not adiajencyList towards other nodes
                os << "[" << i << "]: " << table[i]->getKey() << std::endl;
            } else {
                os << "[" << i << "]: " << table[i]->getKey() << " has adiajencyList towards: ";
                for (auto const &edge: table[i]->getEdges())
                    os << edge->getKey() << " ";
                std::endl(os);
            }
        return os;
    }

private:
    GraphNode<T> **table;
    GraphNode<T> *dummy{};
    int capacity;
    int size;

};

#endif //HASHGRAPH_HASHTABLE_H

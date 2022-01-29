//
// Created by saso on 01/01/2022.
//

#ifndef HASHGRAPH_HASHTABLE_H
#define HASHGRAPH_HASHTABLE_H


#include <list>
#include <ostream>
#include <map>
#include <iomanip>
#include "../Graph/GraphNode.h"

template<typename T>
class HashTable {
public:
    HashTable(int bucketNo);

    HashTable(const std::map<T, std::vector<T>> &graphData, int numbersOfNodes);

    int hashCode(T key) const;

    int insert(GraphNode<T> *graphNode);

    void deleteByKey(T key);

    GraphNode<T> *getByKey(T key);

    GraphNode<T> *findEdge(T sourceNodeKey, T targetNodeKey);

    GraphNode<T> *findEdge(GraphNode<T> *sourceNode, GraphNode<T> *targetNode);

    void addEdge(T sourceNodeKey, T targetNodeKey);

    void removeEdge(T sourceNodeKey, T targetNodeKey);

    int getSize() const;

    GraphNode<T> *operator[](int) const;

    friend std::ostream &operator<<(std::ostream &os, const HashTable<T> &table) {
        os << "HashTable data: " << " capacity: " << table.capacity << " size: " << table.size << " load: "
           << std::setprecision(2) << table.loadFactor << std::endl;
        for (int i = 0; i < table.capacity; i++)
            if (table[i] == nullptr || table[i] == dummy)
                os << "[" << i << "]: is empty" << std::endl;
            else if (table[i]->getEdges().empty()) { // The node has its adiajency list empty
                os << "[" << i << "]: " << table[i]->getKey() << std::endl;
            } else {
                os << "[" << i << "]: " << table[i]->getKey() << " has edges towards: ";
                for (auto const &edge: table[i]->getEdges())
                    os << edge->getKey() << " ";
                std::endl(os);
            }
        return os;
    }

private:
    GraphNode<T> **getNodeRefByKey(T key);

    GraphNode<T> **table;
    constexpr static GraphNode<T> *dummy{};
    int capacity;
    int size;
    float loadFactor{};
};

#endif //HASHGRAPH_HASHTABLE_H

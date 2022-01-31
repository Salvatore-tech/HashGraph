//
// Created by saso on 01/01/2022.
//

#ifndef HASHGRAPH_HASHTABLE_H
#define HASHGRAPH_HASHTABLE_H


#include <list>
#include <ostream>
#include <map>
#include <iomanip>
#include <memory>
#include "../Graph/GraphNode.h"
#include "hashingStrategy/api/HashingStrategy.h"

template<typename T>
class HashTable {
public:
    HashTable(int bucketNo);

//    HashTable(const std::map<T, std::vector<T>> &graphData, int numbersOfNodes);

    int insert(std::shared_ptr<GraphNode<T>> graphNode);

    void deleteByKey(T key);

    std::shared_ptr<GraphNode<T>> getByKey(T key);

    std::shared_ptr<GraphNode<T>> findEdge(T sourceNodeKey, T targetNodeKey);

    std::shared_ptr<GraphNode<T>>
    findEdge(std::shared_ptr<GraphNode<T>> sourceNode, std::shared_ptr<GraphNode<T>> targetNode);

    void addEdge(T sourceNodeKey, T targetNodeKey);

    void removeEdge(T sourceNodeKey, T targetNodeKey);

    int getSize() const;

    std::shared_ptr<GraphNode<T>> operator[](int) const;

    friend std::ostream &operator<<(std::ostream &os, const HashTable<T> &table) {
        os << "HashTable data: " << " capacity: " << table.capacity << " size: " << table.size << " load: "
           << std::setprecision(2) << table.loadFactor << std::endl;
        for (int i = 0; i < table.capacity; i++)
//            if (table[i] == nullptr || table[i] == dummy)
            if (!table[i].get())
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

    std::vector<std::shared_ptr<GraphNode<T>>> table;
    HashingStrategy<T> *hashingStrategy;
    constexpr static GraphNode<T> *dummy{};
    int capacity;
    int size;
    float loadFactor{};
};

#endif //HASHGRAPH_HASHTABLE_H

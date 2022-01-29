//
// Created by saso on 22/01/2022.
//

#ifndef HASHGRAPH_GRAPHNODE_H
#define HASHGRAPH_GRAPHNODE_H

#include <vector>
#include <iostream>
#include "GraphNodeType.h"

template<typename T>
class GraphNode {
public:

    explicit GraphNode(T key);

    T getKey() const;

    std::vector<GraphNode *> &getEdges();

    bool hasEdge(T key);

    bool hasEdge(const GraphNode &targetNode) const;

    void addEdge(std::vector<T> neighboursKey);

    bool addEdge(const GraphNode &targetNode);

    void eraseEdges() {
        edges.clear();
    }

    bool operator==(GraphNode *rhs) const {
        return key == rhs->key;
    }

    template<typename> friend
    class HashTable;

private:
    T key;
    GraphNodeType nodeType;
    std::vector<GraphNode *> edges;
};


#endif //HASHGRAPH_GRAPHNODE_H

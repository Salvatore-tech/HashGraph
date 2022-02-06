//
// Created by saso on 22/01/2022.
//

#ifndef HASHGRAPH_GRAPHNODE_H
#define HASHGRAPH_GRAPHNODE_H

#include <vector>
#include <iostream>
#include <memory>

template<typename T>
class GraphNode {
public:

    explicit GraphNode(T key);

    T getKey() const;

    std::vector<std::weak_ptr<GraphNode<T>>> getEdges();

    bool hasEdge(T key);

    bool hasEdge(const GraphNode<T> &targetNode);

    bool addEdge(std::shared_ptr<GraphNode<T>> targetNode);

    void eraseEdges() {
        edges.clear();
    }

    bool operator==(GraphNode *rhs) const {
        return key == rhs->key;
    }

    template<typename> friend
    class HashTable;

private:
    std::vector<std::weak_ptr<GraphNode<T>>> *getEdgesPtr();

    T key;
    std::vector<std::weak_ptr<GraphNode<T>>> edges;
};


#endif //HASHGRAPH_GRAPHNODE_H

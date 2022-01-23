//
// Created by saso on 22/01/2022.
//

#ifndef HASHGRAPH_GRAPHNODE_H
#define HASHGRAPH_GRAPHNODE_H

#include <vector>

template<typename T>
class GraphNode {
public:

    GraphNode(T key);

    T getKey() const;

    const std::vector<GraphNode *> &getEdges();

    bool hasEdge(T key);

    bool hasEdge(GraphNode *targetNode);

    void addEdge(std::vector<T> neighboursKey);

    void addEdge(GraphNode *targetNode);

    bool operator==(GraphNode *rhs) const {
        return key == rhs->key;
    }

    template<typename> friend
    class HashTable;

private:
    T key;
    std::vector<GraphNode *> edges;
};


#endif //HASHGRAPH_GRAPHNODE_H

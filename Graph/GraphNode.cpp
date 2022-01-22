//
// Created by saso on 22/01/2022.
//

#include "GraphNode.h"

template
class GraphNode<int>;

template<typename T>
GraphNode<T>::GraphNode(T key) {
    GraphNode::key = key;
}

template<typename T>
T GraphNode<T>::getKey() const {
    return key;
}

template<typename T>
const std::vector<GraphNode<T> *> &GraphNode<T>::getEdges() {
    return edges;
}

template<typename T>
void GraphNode<T>::addEdge(const std::vector<T> neighboursKey) {
    for (auto const &neighbourKey: neighboursKey)
        this->edges.push_back(new GraphNode(neighbourKey));
}





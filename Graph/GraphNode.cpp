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
    if (neighboursKey.empty())
        return;
    for (auto const &neighbourKey: neighboursKey) {
        if (!hasEdge(neighbourKey)) // Avoid duplicate neighbours
            this->edges.push_back(new GraphNode(neighbourKey));
    }
}

template<typename T>
void GraphNode<T>::addEdge(GraphNode *targetNode) {
    if (!targetNode || !targetNode->key)
        return;
    if (!hasEdge(targetNode)) // Avoid duplicate neighbours
        this->edges.push_back(targetNode);
}

template<typename T>
bool GraphNode<T>::hasEdge(GraphNode *targetNode) {
    for (const auto &edge: edges)
        if (targetNode->operator==(edge))
            return true;
    return false;
}

template<typename T>
bool GraphNode<T>::hasEdge(T key) {
    return hasEdge(new GraphNode(key));
}





//
// Created by saso on 22/01/2022.
//

#include "GraphNode.h"

template
class GraphNode<int>;

template<typename T>
GraphNode<T>::GraphNode(T key) : key(key) {
    nodeType = Root;
}

template<typename T>
T GraphNode<T>::getKey() const {
    return key;
}

template<typename T>
std::vector<GraphNode<T> *> &GraphNode<T>::getEdges() {
    return edges;
}

template<typename T>
void GraphNode<T>::addEdge(const std::vector<T> neighboursKey) {
    if (neighboursKey.empty())
        return;
    for (auto const &neighbourKey: neighboursKey) {
        addEdge(GraphNode(neighbourKey));
    }
}

template<typename T>
bool GraphNode<T>::addEdge(const GraphNode &targetNode) {
    if (targetNode.key && !hasEdge(targetNode)) {
        auto edgeToAdd = new GraphNode(targetNode.key); // We need to copy the node, otherwise we would alter its data
        edgeToAdd->nodeType = Leaf;
        edgeToAdd->eraseEdges();
        edges.push_back(edgeToAdd);
        return true;
    }
    return false;
}

template<typename T>
bool GraphNode<T>::hasEdge(const GraphNode &targetNode) const {
    for (const auto &edge: edges)
        if (targetNode.operator==(edge))
            return true;
    return false;
}

template<typename T>
bool GraphNode<T>::hasEdge(T keyOfTheEdge) {
    return hasEdge(GraphNode(keyOfTheEdge));
}





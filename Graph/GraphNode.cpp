//
// Created by saso on 22/01/2022.
//

#include "GraphNode.h"

template
class GraphNode<int>;

template<typename T>
GraphNode<T>::GraphNode(T key) : key(key) {

}

template<typename T>
T GraphNode<T>::getKey() const {
    return key;
}

template<typename T>
std::vector<std::weak_ptr<GraphNode<T>>> GraphNode<T>::getEdges() {
    return edges;
}

//template<typename T>
//void GraphNode<T>::addEdge(const std::vector<T> neighboursKey) {
//    if (neighboursKey.empty())
//        return;
//    for (auto const &neighbourKey: neighboursKey) {
//        addEdge(GraphNode(neighbourKey));
//    }
//}

template<typename T>
bool GraphNode<T>::addEdge(std::shared_ptr<GraphNode<T>> targetNode) {
    int index = 1;
    for (auto &edge: edges) {
        if (auto tempSharedPtr = edge.lock()) {
            if (tempSharedPtr->getKey() == targetNode->getKey()) {
                std::cout << "It already has the edge towards " << targetNode->getKey() << std::endl;
                return false;
            }
        } else {
            std::cout << "Found a dangling weak ptr" << std::endl;
            edges.erase(edges.begin() + index);
        }
        index++;
    }
    edges.push_back(targetNode);
    std::cout << "Adding the edge" << std::endl;
    return true;
}

template<typename T>
bool GraphNode<T>::hasEdge(T keyOfTheEdge) {
    return hasEdge(GraphNode<T>(keyOfTheEdge));
}

template<typename T>
bool GraphNode<T>::hasEdge(const GraphNode<T> &targetNode) {
    for (const auto &edge: edges) {
        if (const auto observe = edge.lock()) {
            if (observe->getKey() == targetNode.getKey())
                return true;
        }
    }
    return false;
}





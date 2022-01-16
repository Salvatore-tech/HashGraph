//
// Created by saso on 25/12/2021.
//

#include <iostream>
#include <stack>
#include "DirectedGraph.h"


DirectedGraph::DirectedGraph(int noVertices) {
    adjList.reserve(noVertices);
}

void DirectedGraph::addEdge(int sourceIdx, TreeNode &target) {
    adjList.at(sourceIdx).neighbours.emplace_back(&target);
}

void DirectedGraph::addNode(const TreeNode &node) {
    adjList.push_back(node);
}

bool DirectedGraph::findEdge(int sourceIdx, const TreeNode &node, std::vector<TreeNode *>::iterator &it) {
    it = getIteratorToTargetNodeInNeighbourList(adjList.at(sourceIdx).neighbours, node);
    return it != adjList.at(sourceIdx).neighbours.end();
}

bool DirectedGraph::findEdge(int sourceIdx, const TreeNode &node) {
    auto it = getIteratorToTargetNodeInNeighbourList(adjList.at(sourceIdx).neighbours, node);
    return it != adjList.at(sourceIdx).neighbours.end();
}


std::vector<TreeNode *>::iterator
DirectedGraph::getIteratorToTargetNodeInNeighbourList(std::vector<TreeNode *> &neighbours,
                                                      const TreeNode &node) const {
    return std::find(neighbours.begin(), neighbours.end(), &node);
}

void DirectedGraph::deleteEdge(int sourceIdx, const TreeNode &node) {
    std::vector<TreeNode *>::iterator it;
    if (findEdge(sourceIdx, node, it)) {
        std::cout << "Edge found: erasing" << std::endl;
        adjList.at(sourceIdx).neighbours.erase(it);
    }
}

void DirectedGraph::DFS(int sourceIdx) {

// Initially mark all vertices as not visited
    std::vector<bool> visited(adjList.size() + 1, false);
    std::stack<int> stack;

    // Push the current source node.
    stack.push(adjList.at(sourceIdx).key);

    while (!stack.empty()) {
        // Pop a vertex from stack and print it
        int s = stack.top();
        stack.pop();

        // Stack may contain same vertex twice. So
        // we need to print the popped item only
        // if it is not visited.
        if (!visited[s]) {
            std::cout << s << " ";
            visited[s] = true;
        }

        // Get all adjacent vertices of the popped vertex s
        // If a adjacent has not been visited, then push it
        // to the stack.
        for (auto &neighIt: adjList.at(s).neighbours)
            if (!visited[neighIt->key])
                stack.push(neighIt->key);
    }

}


const std::vector<TreeNode> &DirectedGraph::getAdjList() const {
    return adjList;
}

std::ostream &operator<<(std::ostream &os, const DirectedGraph &graph) {
    for (auto &node: graph.adjList) {
        std::cout << node.key << node.name << " has the following neighbours :";
        for (auto &neighbour: node.neighbours)
            std::cout << neighbour->key << neighbour->name;
        printf("\n");
    }
    return os;
}






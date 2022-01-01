//
// Created by saso on 25/12/2021.
//

#ifndef HASHGRAPH_DIRECTEDGRAPH_H
#define HASHGRAPH_DIRECTEDGRAPH_H


#include <list>
#include <array>
#include <ostream>
#include <map>
#include "TreeNode.h"

class DirectedGraph {
private:
    std::vector<TreeNode> adjList;
public:

    DirectedGraph(int noVertices);

    void addNode(const TreeNode &node);

    void addEdge(int sourceIdx, TreeNode &target);

    bool findEdge(int sourceIdx, const TreeNode &node);

    bool findEdge(int sourceIdx, const TreeNode &node, std::vector<TreeNode *>::iterator &it);

    std::vector<TreeNode *>::iterator
    getIteratorToTargetNodeInNeighbourList(
            std::vector<TreeNode *> &neighbours, const TreeNode &node);

    void deleteEdge(int sourceIdx, const TreeNode &node);

    const std::vector<TreeNode> &getAdjList() const;

    void DFS(int sourceIdx);

    friend std::ostream &operator<<(std::ostream &os, const DirectedGraph &graph);

};

#endif //HASHGRAPH_DIRECTEDGRAPH_H

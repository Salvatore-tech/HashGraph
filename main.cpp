#include <iostream>
#include "Graph/TreeNode.h"
#include "Graph/DirectedGraph.h"

int main() {
    TreeNode node_0 = TreeNode();
    TreeNode node_1 = TreeNode();
    TreeNode node_2 = TreeNode();
    DirectedGraph graph = DirectedGraph(5);

    graph.addNode(node_0);
    graph.addNode(node_1);
    graph.addNode(node_2);

    graph.addEdge(0, node_1);
    graph.addEdge(1, node_2);
    graph.addEdge(2, node_0);


    if (graph.findEdge(0, node_1))
        std::cout << "Edge found" << std::endl;

    std::cout << graph << std::endl;

    graph.DFS(0);

//    graph.DFS(1);




    return 0;
}

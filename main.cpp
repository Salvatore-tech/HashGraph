#include <iostream>
#include "Graph/TreeNode.h"
#include "Graph/DirectedGraph.h"
#include "HashTable.h"

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


    HashTable hashTable = HashTable(5);
    hashTable.insertNode(node_0);
    hashTable.insertNode(node_1);

    std::cout << hashTable[0];
    std::cout << hashTable;


    return 0;
}

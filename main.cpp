#include <iostream>
#include "Graph/TreeNode.h"
#include "Graph/DirectedGraph.h"
#include "HashTable.h"

int main() {
    TreeNode node_0 = TreeNode();
    TreeNode node_1 = TreeNode();
    TreeNode node_2 = TreeNode();
    TreeNode node_3 = TreeNode();
    TreeNode node_4 = TreeNode();

//    DirectedGraph graph = DirectedGraph(5);
//    graph.addNode(node_0);
//    graph.addNode(node_1);
//    graph.addNode(node_2);
//    graph.addEdge(0, node_1);
//    graph.addEdge(1, node_2);
//    graph.addEdge(2, node_0);
//    if (graph.findEdge(0, node_1))
//        std::cout << "Edge found" << std::endl;

//    std::cout << graph << std::endl;
//
//    graph.DFS(0);


    HashTable hashTable = HashTable(3);
    hashTable.insertNode(node_0);
    hashTable.insertNode(node_1);
    hashTable.insertNode(node_2);
//    hashTable.insertNode(node_3);
//    hashTable.insertNode(node_4);>

    std::cout << hashTable;

    hashTable.deleteNode(0);

    if (!hashTable.getByKey(1))
        std::cout << "Key not found" << std::endl;
    else
        std::cout << "Key found" << std::endl;

    std::cout << hashTable;


    return 0;
}

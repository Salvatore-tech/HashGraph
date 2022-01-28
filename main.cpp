#include <iostream>
#include "Graph/GraphNode.h"
#include "HashTable/HashTable.h"
#include "IO/RWFileHandler.h"
#include "IO/FileMetadata.h"
#include "HashTable/HashTableIterator.h"

int main() {
    std::string inputFile = "./resources/input.txt";


    std::map<int, std::vector<int>> graphData;

    auto rwFileHandler = RWFileHandler<int>();
    const FileMetadata &fileMetadata = rwFileHandler.readInputGraph(inputFile, graphData);

    if (fileMetadata.getOperationStatus()) {
        std::cout << "Number of nodes read: " << fileMetadata.getNumberOfNodes() << " number of edges read: "
                  << fileMetadata.getNumberOfEdges() << std::endl;

        HashTable tableFromFile = HashTable<int>(graphData, fileMetadata.getNumberOfNodes() * 2);
        std::cout << tableFromFile << std::endl;

        GraphNode<int> *sourceNode = tableFromFile.getByKey(2);
        GraphNode<int> *targetNode = tableFromFile.getByKey(3);
        sourceNode->addEdge(targetNode);
        std::cout << tableFromFile << std::endl;

        tableFromFile.addEdge(2, 1);
        std::cout << tableFromFile << std::endl;


        if (tableFromFile.findEdge(tableFromFile.getByKey(4), 1))
            std::cout << "The node with key=4 has an edge towards the one with key=1";


        auto tableIterator = HashTableIterator<int>(&tableFromFile);
        tableIterator.dfs(2);
    }


}

#include <iostream>
#include "Graph/TreeNode.h"
#include "HashTable/HashTable.h"
#include "IO/RWFileHandler.h"
#include "IO/FileMetadata.h"

int main() {
    std::string inputFile = "./resources/input.txt";

//// Pure exemples on hash table
//    std::cout << hashTable;
//    hashTable.deleteNode(0);
//    if (!hashTable.getByKey(1))
//        std::cout << "Key not found" << std::endl;
//    else
//        std::cout << "Key found" << std::endl;
//    std::cout << hashTable;

    std::map<int, std::vector<int>> graphData;

    RWFileHandler rwFileHandler = RWFileHandler<int>();
    const FileMetadata &fileMetadata = rwFileHandler.readInputGraph(inputFile, graphData);

    if (fileMetadata.getOperationStatus()) {
        std::cout << "Number of nodes read: " << fileMetadata.getNumberOfNodes() << " number of edges read: "
                  << fileMetadata.getNumberOfEdges() << std::endl;

        HashTable<int> tableFromFile = HashTable<int>(graphData, fileMetadata.getNumberOfNodes() * 2);
        std::cout << tableFromFile << std::endl;


    }


}

#include <iostream>
#include "Graph/GraphNode.h"
#include "HashTable/HashTable.h"
#include "IO/InputOutputHandler.h"
#include "IO/FileMetadata.h"
#include "HashTable/HashTableIterator.h"
#include "HashTable/hashingStrategy/api/DoubleHashingStrategy.h"

int main() {
    std::map<int, std::vector<int>> inputFileGraphBuffer;
    auto inputOutputHandler = InputOutputHandler<int>();

    const FileMetadata &fileMetadata = inputOutputHandler.readInputGraph(inputFileName, inputFileGraphBuffer);

    if (!fileMetadata.getOperationStatus())
        return -1;

    HashTable hashTable = HashTable<int>(inputFileGraphBuffer, fileMetadata.getNumberOfNodes() * 2);
    auto tableIterator = HashTableIterator<int>(hashTable);
    auto hashingStrategy = DoubleHashingStrategy<int>(20);

    int sourceNodeKey;
    int targetNodeKey;
    int choice = 0;
    do {
        inputOutputHandler.displayMenu();
        std::cin >> choice;
        switch (choice) {
            case 1:
                std::cout << hashTable;
                inputOutputHandler.requestInput();
                break;
            case 2:
                inputOutputHandler.getInputAndTargetNode(&sourceNodeKey, &targetNodeKey);
                hashTable.addEdge(sourceNodeKey, targetNodeKey);
                break;
            case 3:
                inputOutputHandler.getInputAndTargetNode(&sourceNodeKey, &targetNodeKey);
                hashTable.removeEdge(sourceNodeKey, targetNodeKey);
                break;
            case 4:
                inputOutputHandler.getInputAndTargetNode(&sourceNodeKey, &targetNodeKey);
                if (hashTable.findEdge(sourceNodeKey, targetNodeKey))
                    std::cout << "Edge found between: " << sourceNodeKey << " --> " << targetNodeKey << std::endl;
                else
                    std::cout <<
                              "There is not an edge between " << sourceNodeKey << " --> " << targetNodeKey << std::endl;
                break;
            case 5:
                std::cout << "Insert source node key: ";
                std::cin >> sourceNodeKey;
                tableIterator.dfs(sourceNodeKey);
                break;
            case 6:
                std::cout << "Insert source node key: ";
                std::cin >> sourceNodeKey;
                hashTable.deleteByKey(sourceNodeKey);
                break;
        }
    } while (choice != 0);
    return 0;
}



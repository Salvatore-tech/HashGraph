#include <iostream>
#include "InputOutputHandler.h"
#include "hash_table/api/HashTable.h"
#include "hash_table/api/HashTableIterator.h"

static const char *const inputFileName = "./resources/input0_2_1.txt";

void displayMenu();

int main() {
    int sourceNodeKey;
    int targetNodeKey;
    int choice = 0;
    std::map<int, std::vector<int>> inputFileGraphBuffer;
    auto inputOutputHandler = InputOutputHandler<int>();
    auto fileMetadata = inputOutputHandler.readInputGraph(inputFileName, inputFileGraphBuffer);

    if (!fileMetadata.getOperationStatus())
        return -1;

    HashTable hashTable = HashTable<int>(inputFileGraphBuffer, fileMetadata.getNumberOfNodes() * 2);
    auto tableIterator = HashTableIterator<int>(hashTable);

    do {
        displayMenu();
        std::cin >> choice;
        switch (choice) {
            case 1:
                std::cout << hashTable;
                inputOutputHandler.requestInput();
                break;
            case 2:
                inputOutputHandler.requestSourceAndTargetNode(&sourceNodeKey, &targetNodeKey);
                hashTable.addEdge(sourceNodeKey, targetNodeKey);
                break;
            case 3:
                inputOutputHandler.requestSourceAndTargetNode(&sourceNodeKey, &targetNodeKey);
                hashTable.removeEdge(sourceNodeKey, targetNodeKey);
                break;
            case 4:
                inputOutputHandler.requestSourceAndTargetNode(&sourceNodeKey, &targetNodeKey);
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
            default:
                std::cout << "Invalid number... retry!\n";
        }
    } while (choice != 0);
    return 0;
}

void displayMenu() {
    std::cout << "\n \t \t [HashGraph menu] \n";
    std::cout << "Choose an operation \n";
    std::cout << "1) Display graph \n";
    std::cout << "2) Add an edge between two nodes \n";
    std::cout << "3) Remove an edge between two nodes \n";
    std::cout << "4) Find an edge between two nodes \n";
    std::cout << "5) Depth first search \n";
    std::cout << "6) Delete a node \n";
    std::cout << "0) Exit \n";
}



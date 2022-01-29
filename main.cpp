#include <iostream>
#include "Graph/GraphNode.h"
#include "HashTable/HashTable.h"
#include "IO/RWFileHandler.h"
#include "IO/FileMetadata.h"
#include "HashTable/HashTableIterator.h"

void displayMenu();

void getInputAndTargetNode(int *sourceNodeKey, int *targetNodeKey);

void requestInput();

int main() {
    std::string inputFile = "./resources/input.txt";
    std::map<int, std::vector<int>> inputFileGraphBuffer;
    auto rwFileHandler = RWFileHandler<int>();

    const FileMetadata &fileMetadata = rwFileHandler.readInputGraph(inputFile, inputFileGraphBuffer);

    if (!fileMetadata.getOperationStatus())
        return -1;

    HashTable hashTable = HashTable<int>(inputFileGraphBuffer, fileMetadata.getNumberOfNodes() * 2);
    auto tableIterator = HashTableIterator<int>(hashTable);

    int sourceNodeKey;
    int targetNodeKey;
    int choice = 0;
    do {
        displayMenu();
        std::cin >> choice;
        switch (choice) {
            case 1:
                std::cout << hashTable;
                requestInput();
                break;
            case 2:
                getInputAndTargetNode(&sourceNodeKey, &targetNodeKey);
                hashTable.addEdge(sourceNodeKey, targetNodeKey);
                break;
            case 3:
                getInputAndTargetNode(&sourceNodeKey, &targetNodeKey);
                hashTable.removeEdge(sourceNodeKey, targetNodeKey);
                break;
            case 4:
                getInputAndTargetNode(&sourceNodeKey, &targetNodeKey);
                hashTable.findEdge(sourceNodeKey, targetNodeKey);
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


}

void requestInput() {
    std::cout << "Press enter to continue";
    std::cin.ignore();
    std::cin.get();
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

void getInputAndTargetNode(int *sourceNodeKey, int *targetNodeKey) {
    std::cout << "Enter the key of the source node: ";
    std::cin >> *sourceNodeKey;
    std::cout << "\nEnter the key of the target node: ";
    std::cin >> *targetNodeKey;
}



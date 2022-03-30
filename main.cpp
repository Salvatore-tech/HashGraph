#include <iostream>
#include "InputOutputHandler.h"
#include "hashgraph/api/HashGraph.h"

void displayMenu();

int main(int argc, char **argv) {
    int sourceNodeKey = -1;
    int targetNodeKey = -1;
    std::map<int, std::vector<int>> inputFileGraphBuffer; // Buffer that contains data from the input txt file
    auto inputOutputHandler = InputOutputHandler<int>();
    char *relativePathToInputFile = inputOutputHandler.getPathToInputFile(argv[1]);

    if (!relativePathToInputFile) {
        std::cerr << "Usage: ./HashGraph inputFileName.txt hashingStrategy[OPTIONAL]" << std::endl;
        return -1;
    }

    auto fileMetadata = inputOutputHandler.readInputGraph(relativePathToInputFile,
                                                          inputFileGraphBuffer); // Filling the buffer

    if (!fileMetadata.getOperationStatus()) // File read failed
        return -1;

    HashGraph hashGraph = HashGraph<int>(
            fileMetadata.getNumberOfNodes() + 1); // Create the hash table and inserting data into it
    hashGraph.setHashingStrategy(argv[2]); // Setting the hashing strategy, by default is linear probing
    hashGraph.fillTable(inputFileGraphBuffer);

    int choice = 0;
    do {
        displayMenu();
        std::cin >> choice;
        switch (choice) {
            case 1:
                std::cout << hashGraph;
                inputOutputHandler.requestInput();
                break;
            case 2:
                inputOutputHandler.requestSourceAndTargetNode(&sourceNodeKey, &targetNodeKey);
                hashGraph.addEdge(sourceNodeKey, targetNodeKey);
                break;
            case 3:
                inputOutputHandler.requestSourceAndTargetNode(&sourceNodeKey, &targetNodeKey);
                hashGraph.removeEdge(sourceNodeKey, targetNodeKey);
                break;
            case 4:
                inputOutputHandler.requestSourceAndTargetNode(&sourceNodeKey, &targetNodeKey);
                if (hashGraph.findEdge(sourceNodeKey, targetNodeKey))
                    std::cout << "Edge found between: " << sourceNodeKey << " --> " << targetNodeKey << std::endl;
                else
                    std::cout <<
                              "There is not an edge between " << sourceNodeKey << " --> " << targetNodeKey << std::endl;
                break;
            case 5:
                std::cout << "Insert source node key: ";
                std::cin >> sourceNodeKey;
                hashGraph.dfs(sourceNodeKey);
                break;
            case 6:
                std::cout << "Insert source node key: ";
                std::cin >> sourceNodeKey;
                hashGraph.deleteByKey(sourceNodeKey);
                break;
            case 0:
                std::cout << "Bye!\n";
                break;
            default:
                std::cout << "Invalid number... retry!\n";
        }
    } while (choice != 0);
    return 0;
}

void displayMenu() {
    std::flush(std::cout);
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



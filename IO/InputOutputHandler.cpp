//
// Created by saso on 02/01/2022.
//

#include <fstream>
#include <iostream>
#include "InputOutputHandler.h"
#include "FileMetadata.h"

template
class InputOutputHandler<int>; // Types of input file data

template<typename T>
FileMetadata
InputOutputHandler<T>::readInputGraph(const std::string &fileName, std::map<T, std::vector<T>> &graphBuffer) const {
    int sourceEdge = 0;
    int destinationEdge = 0;
    int numberOfLinesRead = 0;
    int numberOfEdges = 0;
    int numberOfNodes = 0;
    std::ifstream inputFile;

    std::cout << "Reading " << fileName << std::endl;
    inputFile.open(fileName);
    if (!inputFile.is_open()) {
        std::cout << "Could not open " << fileName << std::endl;
        return {false, 0, 0};
    }

    inputFile >> numberOfNodes >> numberOfEdges; // Read the header that contains the number of nodes and edges

    while (inputFile >> sourceEdge >> destinationEdge) {
        graphBuffer[sourceEdge].push_back(destinationEdge);
        graphBuffer[destinationEdge];
        numberOfLinesRead++;
    }
    inputFile.close();

    std::cout << numberOfLinesRead << "/" << numberOfEdges << " lines has been read" << std::endl;
    if (numberOfLinesRead != numberOfEdges) { // Adding the first row
        std::cout << "The input file: " << fileName << " has been corrupted!" << std::endl;
        return {false, 0, 0};
    }
    return {true, numberOfNodes, numberOfEdges};
}

template<typename T>
void InputOutputHandler<T>::requestSourceAndTargetNode(int *sourceNodeKey, int *targetNodeKey) {
    std::cout << "Enter the key of the source node: ";
    std::cin >> *sourceNodeKey;
    std::cout << "\nEnter the key of the target node: ";
    std::cin >> *targetNodeKey;
}

template<typename T>
void InputOutputHandler<T>::requestInput() {
    std::cout << "Press enter to continue";
    std::cin.ignore();
    std::cin.get();
}



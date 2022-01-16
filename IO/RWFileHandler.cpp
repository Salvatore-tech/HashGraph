//
// Created by saso on 02/01/2022.
//

#include <fstream>
#include <iostream>
#include "RWFileHandler.h"

bool RWFileHandler::readInputGraph(const std::string &fileName, std::map<int, std::vector<int>> &graphBuffer) const {
    int sourceEdge;
    int destinationEdge;
    int numberOfLinesRead = 0;
    int numberOfEdges;
    int numberOfNodes;
    std::ifstream inputFile;

    inputFile.open(fileName);
    if (!inputFile.is_open()) {
        std::cout << "Could not open " << fileName << std::endl;
        return false;
    }

    inputFile >> numberOfNodes >> numberOfEdges;

    while (inputFile >> sourceEdge >> destinationEdge) {
        std::cout << sourceEdge << "\t" << destinationEdge << std::endl;
        graphBuffer[sourceEdge].push_back(destinationEdge);
        numberOfLinesRead++;
    }
    inputFile.close();

    if (numberOfLinesRead < numberOfEdges - 1) { // Adding the first row
        std::cout << "The input file: " << fileName << " has been corrupted!" << std::endl;
        return false;
    }
    return true;
}



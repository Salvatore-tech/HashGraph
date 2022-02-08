//
// Created by saso on 02/01/2022.
//

#ifndef HASHGRAPH_INPUTOUTPUTHANDLER_H
#define HASHGRAPH_INPUTOUTPUTHANDLER_H

#include <map>
#include <vector>
#include "FileMetadata.h"

template<typename T>
class InputOutputHandler {
public:
    FileMetadata readInputGraph(const std::string &fileName, std::map<T, std::vector<T>> &graphBuffer) const;

    void requestSourceAndTargetNode(int *sourceNodeKey, int *targetNodeKey);

    void requestInput();
};


#endif //HASHGRAPH_INPUTOUTPUTHANDLER_H

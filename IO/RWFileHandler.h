//
// Created by saso on 02/01/2022.
//

#ifndef HASHGRAPH_RWFILEHANDLER_H
#define HASHGRAPH_RWFILEHANDLER_H

#include <map>
#include <vector>
#include "FileMetadata.h"

template<typename T>
class RWFileHandler {
public:
    FileMetadata readInputGraph(const std::string &fileName, std::map<T, std::vector<T>> &graphBuffer) const;
};


#endif //HASHGRAPH_RWFILEHANDLER_H

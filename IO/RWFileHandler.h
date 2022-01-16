//
// Created by saso on 02/01/2022.
//

#ifndef HASHGRAPH_RWFILEHANDLER_H
#define HASHGRAPH_RWFILEHANDLER_H

#include <map>
#include <vector>

class RWFileHandler {
private:
public:
    bool readInputGraph(const std::string &fileName, std::map<int, std::vector<int>> &graphBuffer) const;
};


#endif //HASHGRAPH_RWFILEHANDLER_H

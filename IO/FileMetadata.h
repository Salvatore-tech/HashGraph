//
// Created by saso on 20/01/2022.
//

#ifndef HASHGRAPH_FILEMETADATA_H
#define HASHGRAPH_FILEMETADATA_H


class FileMetadata {
public:
    FileMetadata(int operationStatus, int numberOfNodes, int numberOfEdges) {
        this->operationStatus = operationStatus;
        this->numberOfNodes = numberOfNodes;
        this->numberOfEdges = numberOfEdges;
    }

    bool getOperationStatus() const {
        return operationStatus;
    }

    int getNumberOfNodes() const {
        return numberOfNodes;
    }

    int getNumberOfEdges() const {
        return numberOfEdges;
    }

private:
    bool operationStatus;
    int numberOfNodes;
    int numberOfEdges;
};


#endif //HASHGRAPH_FILEMETADATA_H

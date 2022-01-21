//
// Created by saso on 25/12/2021.
//

#ifndef HASHGRAPH_TREENODE_H
#define HASHGRAPH_TREENODE_H

#include <string>
#include <vector>

static int counter = 0;

class TreeNode {
public:
    TreeNode() { this->key = counter++; }

    TreeNode(const std::string &name, const std::vector<TreeNode *> &neighbours) : name(name), neighbours(neighbours) {
        this->key = counter++;
        this->name = name;
        this->neighbours = neighbours;
    }

    TreeNode(int key) {
        this->key = key;
    }


    int getKey() const {
        return key;
    }

    void setKey(int key) {
        TreeNode::key = key;
    }

    const std::string &getName() const {
        return name;
    }

    void setName(const std::string &name) {
        TreeNode::name = name;
    }

    const std::vector<TreeNode *> &getNeighbours() const {
        return neighbours;
    }

    void setNeighbours(const std::vector<int> neighboursKey) {
        for (auto const &neighbourKey: neighboursKey)
            this->neighbours.push_back(new TreeNode(neighbourKey));
    }


    bool operator==(const TreeNode &rhs) const {
        return neighbours == rhs.neighbours &&
               name == rhs.name;
    }

    bool operator!=(const TreeNode &rhs) const {
        return !(rhs == *this);
    }

    friend class HashTable;

    friend class DirectedGraph;

private:
    int key;
    std::string name;
    std::vector<TreeNode *> neighbours;
};

#endif //HASHGRAPH_TREENODE_H

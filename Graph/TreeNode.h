//
// Created by saso on 25/12/2021.
//

#ifndef HASHGRAPH_TREENODE_H
#define HASHGRAPH_TREENODE_H

#include <string>
#include <vector>

static int counter = 0;

class TreeNode {
private:
    // TODO
public:

    int id;
    std::string name;
    std::vector<TreeNode *> neighbours;

    TreeNode() { this->id = counter++;}

    TreeNode(const std::string &name, const std::vector<TreeNode *> &neighbours) : name(name), neighbours(neighbours) {
        this->id = counter++;
        this->name = name;
        this->neighbours = neighbours;
    }

    TreeNode(const std::string &name) : name(name) {
        this->id = counter++;
        this->name = name;
        this->neighbours.reserve(5);
    }


    int getId() const {
        return id;
    }

    void setId(int id) {
        TreeNode::id = id;
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

    void setNeighbours(const std::vector<TreeNode *> &neighbours) {
        TreeNode::neighbours = neighbours;
    }


    bool operator==(const TreeNode &rhs) const {
        return neighbours == rhs.neighbours &&
               name == rhs.name;
    }

    bool operator!=(const TreeNode &rhs) const {
        return !(rhs == *this);
    }
};

#endif //HASHGRAPH_TREENODE_H

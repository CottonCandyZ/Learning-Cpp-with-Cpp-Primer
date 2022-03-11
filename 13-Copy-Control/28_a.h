//
// Created by CottonCandyZ on 3/7/22.
//

#ifndef C__PRIMER_28_A_H
#define C__PRIMER_28_A_H

#include <string>

class TreeNode {
public:
    TreeNode() :
            value(std::string()), count(new int(1)), left(nullptr), right(nullptr) {}

    TreeNode(const TreeNode &rhs) : value(rhs.value), left(rhs.left), right(rhs.right) {
        ++*count;
    }

    TreeNode &operator=(const TreeNode &rhs);

    ~TreeNode() {

    }

private:
    std::string value;
    int *count;
    TreeNode *left;
    TreeNode *right;
};

TreeNode &TreeNode::operator=(const TreeNode &rhs) {
    ++*rhs.count;
    if (--*count == 0) {
        if (left) {
            delete left;
            left = nullptr;
        }
        if (right) {
            delete right;
            right = nullptr;
        }
        delete count;
        count = nullptr;
    }
    value = rhs.value;
    left = rhs.left;
    right = rhs.right;
    ++*count;
    return *this;
}

#endif //C__PRIMER_28_A_H

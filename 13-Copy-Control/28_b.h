//
// Created by CottonCandyZ on 3/7/22.
//

#ifndef C__PRIMER_28_B_H
#define C__PRIMER_28_B_H

#include "28_a.h"

class BinStrTree {
private:
    TreeNode *root;
public:
    BinStrTree() : root(new TreeNode()){}
    BinStrTree(const BinStrTree& bst) : root(new TreeNode(*bst.root)) {}
    BinStrTree& operator=(const BinStrTree& bst);
    ~BinStrTree() { delete root; }
};

BinStrTree &BinStrTree::operator=(const BinStrTree &bst) {
    TreeNode *new_root = new TreeNode(*bst.root);
    delete root;
    root = new_root;
    return *this;
}

#endif //C__PRIMER_28_B_H

#ifndef TREE_H
#define TREE_H

#include <cstring>
#include <vector>

struct TreeNode {
    char* data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(const char* val);
    ~TreeNode();
};

TreeNode* buildBalancedTree(char** arr, int start, int end);
int countStartingWith(TreeNode* root, char target);
TreeNode* convertToSearchTree(TreeNode* root);

#endif

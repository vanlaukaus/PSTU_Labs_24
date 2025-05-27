#include "tree.h"
#include <algorithm>

TreeNode::TreeNode(const char* val) {
    data = new char[strlen(val) + 1];
    strcpy(data, val);
    left = right = nullptr;
}

TreeNode::~TreeNode() {
    delete[] data;
    delete left;
    delete right;
}

TreeNode* buildBalancedTree(char** arr, int start, int end) {
    if (start > end) return nullptr;
    int mid = (start + end) / 2;
    TreeNode* node = new TreeNode(arr[mid]);
    node->left = buildBalancedTree(arr, start, mid - 1);
    node->right = buildBalancedTree(arr, mid + 1, end);
    return node;
}

void collectElements(TreeNode* root, std::vector<char*>& elements) {
    if (!root) return;
    collectElements(root->left, elements);
    elements.push_back(strdup(root->data));
    collectElements(root->right, elements);
}

TreeNode* convertToSearchTree(TreeNode* root) {
    std::vector<char*> elements;
    collectElements(root, elements);
    std::sort(elements.begin(), elements.end(), [](const char* a, const char* b) {
        return strcmp(a, b) < 0;
    });
    TreeNode* newRoot = buildBalancedTree(elements.data(), 0, elements.size() - 1);
    for (auto elem : elements) delete[] elem;
    return newRoot;
}

int countStartingWith(TreeNode* root, char target) {
    if (!root) return 0;
    int count = (root->data[0] == target) ? 1 : 0;
    return count + countStartingWith(root->left, target) + countStartingWith(root->right, target);
}

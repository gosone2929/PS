#include <iostream>
#include "TreeNode.cpp"

using namespace std;

class Solution {
public:
    void godo(TreeNode* root) {
        if (root == nullptr) {
            return;
        }
        invertTree(root->left);
        invertTree(root->right);
        swap(root->left, root->right);
    }
    TreeNode* invertTree(TreeNode* root) {
        godo(root);
        return root;
    }
};
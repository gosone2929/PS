#include <iostream>
#include "TreeNode.cpp"
using namespace std;


class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        vector<int> currentTree;
        function<void(TreeNode* node)> dfs = [&](TreeNode* node){
            if (not node) {
                return;
            }
            dfs(node->left);
            currentTree.push_back(node->val);
            dfs(node->right);
        };
        dfs(root);
        return currentTree[k];
    }
};
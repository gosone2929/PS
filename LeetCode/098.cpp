#include <iostream>
#include "TreeNode.cpp"
using namespace std;

class Solution {
public:

    bool isValidBST(TreeNode* root) {
        vector<int> intVectorValue = {};
        function<void(TreeNode*)> dfs = [&](TreeNode* node) {
            if (not node) {
                return;
            }
            dfs(node->left);
            intVectorValue.push_back(node->val);
            dfs(node->right);
        };
        dfs(root);
        bool isUnique = unique(intVectorValue.begin(), intVectorValue.end()) == intVectorValue.end();
        return isUnique and is_sorted(intVectorValue.begin(), intVectorValue.end());
    }
    
};

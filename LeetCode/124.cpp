#include <iostream>
#include "TreeNode.cpp"

using namespace std;

class Solution {
public:
    int maxVal = -5000;

    int dfs(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        int curVal = root->val;
        int leftVal = dfs(root->left);
        int rightVal = dfs(root -> right);
        maxVal = max({maxVal, curVal, curVal + leftVal, curVal + rightVal, curVal + leftVal + rightVal});
        return max({curVal, curVal + leftVal, curVal + rightVal});
    } 
    
    int maxPathSum(TreeNode* root) {
        dfs(root);
        return maxVal;
    }
};
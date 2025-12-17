struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
#include <iostream>>
using namespace std;
class Solution {
public:
    int maxDepth(TreeNode* current) {
        if (current == nullptr) {
            return 0;
        }
        return 1 + max(maxDepth(current->left), maxDepth(current->right));
    }
    int maxDepth(TreeNode* root) {
        return maxDepth(root);
    }
};
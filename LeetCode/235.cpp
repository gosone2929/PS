#include <iostream>
#include "TreeNode.cpp"

using namespace std;
class Solution {
public:
    TreeNode* lowestCommonAncestor2(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> path;
        function<bool(TreeNode*, TreeNode*)> dfs = [&](TreeNode* node, TreeNode* target) {
            if (not node) {
                return false;
            }
            path.push_back(node);
            if (node->val == target->val) {
                return true;
            }
            
            if (dfs(node->left, target)|| dfs(node->right, target)) {
                return true;
            }
            path.pop_back();
            return false;
        };

        dfs(root, p);
        auto pPath = path;
        path = {};
        dfs(root, q);
        auto qPath = path;
        
        int left = 0;
        while (left + 1 < pPath.size()) {
            if (pPath[left + 1]->val == qPath[left + 1]->val) {
                left += 1;
            }
            break;
        }
        return pPath[left];
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (not root) {
            return NULL;
        }

        int rootVal = root->val;
        if (p->val < rootVal and q->val < rootVal) {
            return lowestCommonAncestor(root->left, p, q);
        }
        if (rootVal < p->val and rootVal < q->val) {
            return lowestCommonAncestor(root->right, p, q);
        }
        return root;
    }

};
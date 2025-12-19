#include <iostream>
#include <numeric>
#include "TreeNode.cpp"

using namespace std;
class Solution {
public:
    bool answer = false;

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        function<string(TreeNode*)> serialize = [&](TreeNode* cur) {
            if (!cur) {
                return string("#");
            }
            string tt = "(" + to_string(cur->val) + "),(" + serialize(cur->left) + "),(" + serialize(cur->right) + ")";
            return tt;
        };
        return serialize(root).find(serialize(subRoot)) != string::npos;
    }
};

int main() {

}
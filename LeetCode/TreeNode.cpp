#include <iostream>
#include <deque>
#include <vector>
#include <optional>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}

    void displayTreeNode() {
        deque<TreeNode*> d = {this};

        while (!d.empty()) {
            TreeNode* node = d.front();
            d.pop_front();

            optional<int> leftVal;
            optional<int> rightVal;

            if (node->left)  leftVal = node->left->val;
            if (node->right) rightVal = node->right->val;

            cout << node->val << ": ";
            cout << (leftVal ? to_string(*leftVal) : "null") << ", ";
            cout << (rightVal ? to_string(*rightVal) : "null") << endl;

            if (node->left)  d.push_back(node->left);
            if (node->right) d.push_back(node->right);
        }
    }
};
#include <iostream>
#include "TreeNode.cpp"
#include <numeric>
using namespace std;

class Codec {
public:

    
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root) return "null";

        vector<optional<int>> temp;

        function<void(TreeNode*, int)> dfs = [&](TreeNode* node, int index) {
            if (temp.size() <= index) {
                temp.resize(index + 1);
            }

            if (!node) {
                temp[index] = nullopt;
                return;
            }

            temp[index] = node->val;
            dfs(node->left, index * 2 + 1);
            dfs(node->right, index * 2 + 2);
        };

        dfs(root, 0);

        string result;
        for (int i = 0; i < temp.size(); i++) {
            if (i) result += ",";
            result += temp[i].has_value() ? to_string(*temp[i]) : "null";
        }
        return result;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {

        return nullptr;
    }
};

int main() {

}
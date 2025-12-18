#include <iostream>>
#include "TreeNode.cpp"

using namespace std;

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        deque<pair<TreeNode*, int>> d = {{root, 0}};
        vector<vector<int>> answer = {};
        if (not root) {
            return {};
        }
        while (not d.empty()) {
            
            auto [node, depth] = d.front(); 
            cout << node->val << endl;
            d.pop_front();
            

            if (answer.size() < depth) {
                answer.push_back({});
            }
            cout << answer.size() << endl;
            answer[depth].push_back(node->val);

            if (node->left != nullptr) {
                d.push_back({node->left , depth + 1});
            }
            if (node->right != nullptr) {
                d.push_back({node->right , depth + 1});
            }
            cout << "끝" << endl;
        }
        return answer;
    }
};

TreeNode* makeT1() {
    TreeNode* t2 = new TreeNode(9);
    TreeNode* t3 = new TreeNode(15);
    TreeNode* t4 = new TreeNode(7);
    TreeNode* t5 = new TreeNode(20, t3, t4);
    TreeNode* t6 = new TreeNode(3, t2, t6);
    return t6;

}

int main() {
    auto t = makeT1();
    Solution().levelOrder(t);
}
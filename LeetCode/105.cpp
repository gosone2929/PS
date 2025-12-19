#include <iostream>
#include "TreeNode.cpp"

using namespace std;
class Solution {
public:
    vector<int> preoreders;
    vector<int> inorders;
    int inorderIndex = 0;
    optional<TreeNode*> findAndMake(int start, int end) {
        if (start > end) {
            return nullopt;
        }else if (start == end)  {
            inorderIndex += 1;
            return new TreeNode(inorders[inorderIndex - 1]);
        }
        optional<int> targetIndex;
        int targetInorderValue = inorders[inorderIndex];
        for (int i = start; i <= end; i += 1) {
            if (inorders[inorderIndex] == preoreders[i]) {
                targetIndex = i;
                break;
            }
        }
        
        if (!targetIndex.has_value()) {
            return nullopt;
        }
    
        inorderIndex += 1;
        
        auto left = findAndMake(start, targetIndex.value() - 1);
        auto right = findAndMake(targetIndex.value() + 1, end);
        
        return new TreeNode(
            targetInorderValue,
            left.has_value() ? left.value() : nullptr,
            right.has_value() ? right.value() : nullptr
        );
    };

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        inorders = inorder;
        preoreders = preorder;
        auto answer = findAndMake(0, size(inorder) - 1);
        return answer.has_value() ? answer.value() : nullptr;
    }
};

int main() {
    vector<int> inorder = {9,3,15,20,7}, preorder = {3, 9, 20, 15, 7};
    auto cur = Solution().buildTree(preorder, inorder);

}
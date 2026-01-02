#include <iostream>
#include "ListNode.cpp"

using namespace std;
class Solution {
public:
    bool flag = false;
    int targetN;
    int dfs(ListNode* node) {
        if (node == nullptr) {
            return 0;
        }
        int reverseDepth = dfs(node->next);
        if (not flag and reverseDepth == targetN) {
            node->next = node->next->next;
            flag = true;
        }

        return reverseDepth + 1;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        targetN = n;
        ListNode* root = new ListNode();
        root->next = head;
        dfs(root);
        return root->next;
    }
};
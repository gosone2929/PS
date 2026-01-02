#include <ListNode.cpp>
#include <iostream>

using namespace std;
class Solution {
public:
    bool dfs(ListNode* slow, ListNode* fast) {
        if (not fast or not slow) {
            return true;
        }
        if (slow == fast) {
            return false;
        }
        return dfs(slow->next, fast->next->next);
    }
    bool hasCycle(ListNode *head) {
        return dfs(head->next, head->next->next);
    }
};
#include <iostream>
#include "ListNode.cpp"

using namespace std;

class Solution {
public:

    void dfs(ListNode* node, ListNode* prev) {
        ListNode* next = node->next;
        if (next) {
            dfs(next, node);
        }
        node->next = prev;
    }
    ListNode* reverseList(ListNode* head) {
        dfs(head, NULL);
        return head;
    }
};
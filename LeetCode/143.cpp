#include <iostream>
#include "ListNode.cpp"

using namespace std;


class Solution {
public:
    int halfDepth = -1;
    bool flag = false;
    ListNode* tail = nullptr;
    pair<ListNode*, int> dfs(ListNode* node, int depth) {
        if (not node) {
            halfDepth = depth / 2;
            tail = new ListNode();
            return {tail, 0} ;
        }
        auto [prev, prevDepth] =  dfs(node->next, depth + 1);
        if (not flag) {
            prev->next = node;
            if (halfDepth == prevDepth) {
                flag = true;
                node->next = nullptr;
            }
        }
        return {node, prevDepth + 1};
    }

    void reorderList(ListNode* head) {
        dfs(head, 0);
        ListNode* answer = head;
        tail = tail->next;

        const ListNode* temp = head;
        cout << "HEAD Values:";
        while (temp) {
            cout << temp->val;
            temp = temp->next;
        }

        temp = tail;
        cout << "tail Values:";
        while (temp) {
            cout << temp->val;
            temp = temp->next;
        }

        while (head and tail) {
            cout << "HEAD:" << head->val <<  ", TAIL:" << tail->val << endl;

            auto currentHead = head;
            auto currentTail = tail;
            head = head->next;
            tail = tail->next;
            currentHead->next = currentTail;
            currentTail->next = head;
        }
    }
};
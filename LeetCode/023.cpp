#include <iostream>
#include "ListNode.cpp"

using namespace std;

class Solution {
    struct TestNode {
        bool operator() (ListNode* t0, ListNode* t1) {
            return t0->val < t1->val;
        }
    };
public:
    vector<ListNode*> q;
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, TestNode> pq;
        ListNode* answer = new ListNode();
        ListNode* prev = answer;

        for (auto p: lists) {
            if (p) {
                pq.push(p);
            }
        }

        while (pq.size() > 0) {
            ListNode *front = pq.top();
            pq.pop();
            if(front->next) {
                pq.push(front->next);
            }
            prev->next = front;
            prev = prev->next;
        }

        return answer->next;
    }
};
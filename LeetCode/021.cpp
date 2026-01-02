#include <iostream>
#include "ListNode.cpp"

using namespace std;

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* left = list1;
        ListNode* right = list2;
        ListNode* answer = new ListNode();
        ListNode* root = answer;
        while (left and right) {
            if (left->val < right->val) {
                answer->next = left;
                left = left->next;
            }else {
                answer->next = right;
                right = right->next;
            }
            answer = answer->next;
        }

        if (left) {
            answer->next = left;
        }
        if (right) {
            answer->next = right;
        }
        return root->next;
    }
};
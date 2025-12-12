


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 
class Solution {
public:

    ListNode* rn(ListNode& current) {
        ListNode& node = *current.next;
        if (node.next != nullptr) {
            return rn(node);
        }
    }
    ListNode* reverseList(ListNode* head) {
        
    }
};
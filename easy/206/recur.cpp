/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* node) {
        if(node == nullptr || node->next == nullptr) {
            return node;
        }
        ListNode *lastNode = reverseList(node->next);
        node->next->next = node;
        node->next = nullptr;
        return lastNode;
    }
};

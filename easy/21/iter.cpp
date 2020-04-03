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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1 == nullptr) return l2;
        if(l2 == nullptr) return l1;
        
        ListNode *head;
        if(l1->val <= l2->val) {
            head = l1;
            l1 = l1->next;
        }
        else {
            head = l2;
            l2 = l2->next;
        }
        
        ListNode *temp = head;
        while(l1 != nullptr && l2 != nullptr) {
            if(l1->val <= l2->val) {
                temp->next = l1;
                l1 = l1->next;
            } else {
                temp->next = l2;
                l2 = l2->next;
            }
            temp = temp->next;
        }
        
        while(l1 != nullptr) {
            temp->next = l1;
            l1 = l1->next;
            temp = temp->next;
        }
        while(l2 != nullptr) {
            temp->next = l2;
            l2 = l2->next;
            temp = temp->next;
        }
        
        return head;
    }
};

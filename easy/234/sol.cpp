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
    bool isPalindrome(ListNode* head) {
        ListNode *slow=head, *fast=head;
        while(fast != nullptr && fast->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
        }
        if(fast != nullptr) slow = slow->next;
        
        //reversing second half
        ListNode *prev=nullptr, *cur=slow, *next=nullptr;
        while(cur != nullptr) {
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        
        ListNode *temp = head;
        while(prev) {
            if(prev->val != temp->val) return false;
            prev = prev->next;
            temp = temp->next;
        }
        return true;
    }
};

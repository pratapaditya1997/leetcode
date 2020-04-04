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
    ListNode* merge(ListNode *l, ListNode *r) {
        ListNode *head = nullptr;
        if(l->val <= r->val) {
            head = l;
            l = l->next;
        } else {
            head = r;
            r = r->next;
        }
        
        ListNode *temp = head;
        while(l != nullptr && r != nullptr) {
            if(l->val <= r->val) {
                temp->next = l;
                l = l->next;
            } else {
                temp->next = r;
                r = r->next;
            }
            temp = temp->next;
        }
        
        if(l != nullptr) temp->next = l;
        if(r != nullptr) temp->next = r;
        return head;
    }
    
    ListNode* sortList(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return head;
        ListNode *fast = head->next, *slow = head;
        while(fast != nullptr && fast->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
        }
        
        ListNode *secondHalf = sortList(slow->next);
        slow->next = nullptr;
        ListNode *firstHalf = sortList(head);
        return merge(firstHalf, secondHalf);
    }
};

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
    int calcSize(ListNode *head) {
        ListNode *temp = head;
        int ret = 0;
        while(temp != nullptr) {
            ret++;
            temp = temp->next;
        }
        return ret;
    }
    
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len = calcSize(head);
        n = len-n;
        
        ListNode *prev=nullptr, *cur=head;
        while(n--){
            prev = cur;
            cur = cur->next;
        } 
        if(prev == nullptr) { // first node delete case
            head = cur->next;
        } else prev->next = cur->next;
        return head;
    }
};

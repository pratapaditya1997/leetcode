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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode *ans = new ListNode(0);
        ListNode *temp = ans;
        while(l1 != nullptr || l2 != nullptr || carry) {
            if(l1 != nullptr) {
                carry += l1->val;
                l1 = l1->next;
            }
            if(l2 != nullptr) {
                carry += l2->val;
                l2 = l2->next;
            }
            temp->next = new ListNode(carry%10);
            temp = temp->next;
            carry /= 10;
        }
        return ans->next;
    }
};

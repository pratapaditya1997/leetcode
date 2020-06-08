class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(head == nullptr) return nullptr;

        ListNode *temp, *cur = head, *prev = nullptr;
        while(m>1) {
            prev = cur;
            cur = cur->next;
            --m; --n;
        }

        ListNode *prev_mth = prev, *mth = cur;
        while(n) {
            temp = cur->next;
            cur->next = prev;
            prev = cur;
            cur = temp;
            --n;
        }
        
        if(prev_mth != nullptr) prev_mth->next = prev;
        else head = prev;
        mth->next = cur;
        return head;
    }
};
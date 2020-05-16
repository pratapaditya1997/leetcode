/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

struct comp {
    bool operator()(const ListNode* l, ListNode* r) {
        return l->val > r->val;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* head = new ListNode();
        priority_queue<ListNode*, vector<ListNode*>, comp> pq;
        for(auto node: lists) {
            if(node != nullptr) pq.push(node);
        }
        
        ListNode* cur = head;
        while(!pq.empty()) {
            ListNode* temp = pq.top(); pq.pop();
            cur->next = temp;
            cur = cur->next;
            if(temp->next != nullptr) pq.push(temp->next);
        }
        return head->next;
    }
};

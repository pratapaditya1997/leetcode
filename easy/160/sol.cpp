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
    
    ListNode* moveDelta(ListNode *head, int delta) {
        ListNode *temp = head;
        while(delta--) {
            temp = temp->next;
        }
        return temp;
    }
    
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int sizeA = calcSize(headA);
        int sizeB = calcSize(headB);
        
        if(sizeA < sizeB) {
            swap(headA, headB);
            swap(sizeA, sizeB);
        }
        
        int delta = sizeA - sizeB;
        ListNode *tempA = moveDelta(headA, delta), *tempB = headB;
        
        while(tempA != nullptr && tempB != nullptr) {
            if(tempA == tempB) return tempA;
            tempA = tempA->next;
            tempB = tempB->next;
        }
        return nullptr;
    }
};

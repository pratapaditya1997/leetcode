/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == nullptr) return head;
        // insert additional clone node between every orig node
        Node *cur = head, *temp, *clone;
        while(cur != nullptr) {
            temp = cur->next;
            cur->next = new Node(cur->val);
            cur->next->next = temp;
            cur = temp;
        }
        
        // adjust random pointers for the clone nodes
        cur = head;
        while(cur != nullptr) {
            clone = cur->next;
            clone->random = cur->random ? cur->random->next : nullptr;
            cur = cur->next->next;
        }
        
        // separate orig and clone list
        cur = head, clone = head->next, temp = clone;
        while(cur != nullptr && clone != nullptr) {
            cur->next = cur->next->next;
            clone->next = clone->next ? clone->next->next : nullptr;
            cur = cur->next;
            clone = clone->next;
        }
        return temp;
    }
};

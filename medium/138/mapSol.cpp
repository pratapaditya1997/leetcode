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
        map<Node*, Node*> map;
        
        Node *orig = head, *clone = nullptr;
        while(orig != nullptr) {
            clone = new Node(orig->val);
            map[orig] = clone;
            orig = orig->next;
        }
        
        orig = head;
        while(orig != nullptr) {
            clone = map[orig];
            clone->next = map[orig->next];
            clone->random = map[orig->random];
            orig = orig->next;
        }
        return map[head];
    }
};

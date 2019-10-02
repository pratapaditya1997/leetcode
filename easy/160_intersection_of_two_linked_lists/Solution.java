/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public ListNode getIntersectionNode(ListNode headA, ListNode headB) {
        HashMap<ListNode,Integer> hasOccured = new HashMap<ListNode,Integer>(); 
        ListNode res = null;
        
        ListNode temp = headA;
        while(temp != null) {
            hasOccured.put(temp,1);
            temp = temp.next;
        }
        
        temp = headB;
        while(temp != null) {
            if(hasOccured.containsKey(temp)) {
                return temp;
            }
            temp = temp.next;
        }
        return res;
    }
}

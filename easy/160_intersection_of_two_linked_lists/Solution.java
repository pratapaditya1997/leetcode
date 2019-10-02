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
        if(headA == null || headB == null) return null;
        
        Integer sizeA = calcSize(headA);
        Integer sizeB = calcSize(headB);
        
        ListNode curA = headA, curB = headB;
        if(sizeA > sizeB) {
            curA = moveDelta(curA, sizeA - sizeB);
        } else {
            curB = moveDelta(curB, sizeB - sizeA);
        }
        
        while(curA != null && curB != null) {
            if(curA == curB) return curA;
            curA = curA.next;
            curB = curB.next;
        }
        return null;
    }
    
    public Integer calcSize(ListNode temp) {
        Integer result = 0;
        while(temp != null) {
            ++result;
            temp = temp.next;
        }
        return result;
    }
    
    public ListNode moveDelta(ListNode temp,Integer delta) {
        while(delta > 0) {
            temp = temp.next;
            --delta;
        }
        return temp;
    }
}

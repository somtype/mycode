/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode swapPairs(ListNode head) {
        ListNode preHead = new ListNode();
        preHead.next = head;
        ListNode p = preHead;
        while (p.next != null && p.next.next != null) {
            ListNode node1 = p.next;
            ListNode node2 = p.next.next;
            // exchange node1 and node2
            node1.next = node2.next;
            node2.next = node1;
            p.next = node2;
            // exchange pb.next and pf.next
            p = p.next.next;
        }
        return preHead.next;
    }
}

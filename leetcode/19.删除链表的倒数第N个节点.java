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
	public ListNode removeNthFromEnd(ListNode head, int n) {
		ListNode prehead = new ListNode();
		prehead.next = head;
		//双指针，pf先往前探n步
		ListNode pb, pf;
		pb = pf = prehead;
		for (int i = 0; i < n; i++) {
			pf = pf.next;
		}
		while (pf.next != null) {
			pb = pb.next;
			pf = pf.next;
		}
		pb.next = pb.next.next;
		return prehead.next;
	}
}

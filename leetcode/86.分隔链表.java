/*
 * @lc app=leetcode.cn id=86 lang=java
 *
 * [86] 分隔链表
 */

// @lc code=start
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
    public ListNode partition(ListNode head, int x) {
        ListNode preHead = new ListNode();
        preHead.next = head;
        ListNode newPreHead = new ListNode();
        ListNode ptr = preHead, node = newPreHead;
        while (ptr.next != null) {
            if (ptr.next.val < x) {
                node.next = new ListNode(ptr.next.val);
                node = node.next;
                ptr.next = ptr.next.next;
            } else {
                ptr = ptr.next;
            }
        }
        node.next = preHead.next;
        return newPreHead.next;
    }
}
// @lc code=end

/*
 * @lc app=leetcode.cn id=25 lang=java
 *
 * [25] K 个一组翻转链表
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
    public ListNode reverseKGroup(ListNode head, int k) {
        ListNode preHead = new ListNode(0);
        preHead.next = head;
        ListNode preNode = preHead;
        while (HaveNode(preNode, k)) {
            ListNode[] node = new ListNode[k];
            ListNode p = preNode.next;
            for (int i = 0; i < k; i++) {
                node[i] = p;
                p = p.next;
            }
            node[0].next = node[k - 1].next;
            preNode.next = node[k - 1];
            for (int i = k - 1; i >= 1; i--) {
                node[i].next = node[i - 1];
            }
            preNode = node[0];
        }
        return preHead.next;
    }
    boolean HaveNode(ListNode preNode, int k) {
        boolean have = true;
        for (int i = 0; i < k; i++) {
            if (preNode.next == null) {
                have = false;
                break;
            }
            preNode = preNode.next;
        }
        return have;
    }
}
// @lc code=end

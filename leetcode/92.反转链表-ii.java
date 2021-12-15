/*
 * @lc app=leetcode.cn id=92 lang=java
 *
 * [92] 反转链表 II
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
    public ListNode reverseBetween(ListNode head, int left, int right) {
        ListNode preHead = new ListNode();
        preHead.next = head;
        ListNode ptr = preHead;
        ListNode backNode, frontNode;
        backNode = frontNode = null;
        ListNode[] node = new ListNode[right - left + 1];
        int index = 0, i = 0;
        while (ptr != null) {
            if (index == left - 1) {
                backNode = ptr;
            } else if (index == right + 1) {
                frontNode = ptr;
            } else if (index >= left && index <= right) {
                node[i] = ptr;
                i++;
            }
            ptr = ptr.next;
            index++;
        }
        backNode.next = node[right - left];
        node[0].next = frontNode;
        for (int j = right - left; j >= 1; j--) {
            node[j].next = node[j - 1];
        }
        return preHead.next;
    }
}
// @lc code=end

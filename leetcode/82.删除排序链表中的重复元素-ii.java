/*
 * @lc app=leetcode.cn id=82 lang=java
 *
 * [82] 删除排序链表中的重复元素 II
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
    public ListNode deleteDuplicates(ListNode head) {
        int[] hashMap = new int[201];
        ListNode preHead = new ListNode(0);
        preHead.next = head;
        ListNode ptr = preHead;
        while (ptr.next != null) {
            hashMap[ptr.next.val + 100]++;
            ptr = ptr.next;
        }
        ptr = preHead;
        while (ptr.next != null) {
            if (hashMap[ptr.next.val + 100] > 1) {
                ptr.next = ptr.next.next;
            } else {
                ptr = ptr.next;
            }
        }
        return preHead.next;
    }
}
// @lc code=end

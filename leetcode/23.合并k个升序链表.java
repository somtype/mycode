/*
 * @lc app=leetcode.cn id=23 lang=java
 *
 * [23] 合并K个升序链表
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
    public ListNode mergeKLists(ListNode[] lists) {
        int k = lists.length;
        ListNode newHead = null;
        for(int i = 0; i < k; i++){
            newHead = merge2Lists(newHead, lists[i]);
        }
        return newHead;
    }
    ListNode merge2Lists(ListNode head1, ListNode head2){
        if(head1 == null || head2 == null){
            return head1 != null ? head1 : head2;
        }
        ListNode preHead = new ListNode();
        ListNode p, p1, p2;
        p = preHead;
        p1 = head1;
        p2 = head2;
        while(p1 != null && p2 != null){
            if(p1.val < p2.val){
                p.next = p1;
                p1 = p1.next;
            }
            else{
                p.next = p2;
                p2 = p2.next;
            }
            p = p.next;
        }
        p.next = (p1 != null ? p1 : p2);
        return preHead.next;
    }
}
// @lc code=end


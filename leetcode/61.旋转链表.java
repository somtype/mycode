/*
 * @lc app=leetcode.cn id=61 lang=java
 *
 * [61] 旋转链表
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
    public ListNode rotateRight(ListNode head, int k) {
        if(head == null) return null;
        int nodeNum = 0;
        ListNode ptr = new ListNode(0);
        ptr.next = head;
        while(ptr.next != null){
            ptr = ptr.next;
            nodeNum ++;
        }
        int realK = k % nodeNum;
        ptr.next = head; //成环
        //断链
        ptr = head;
        for(int i = 0; i < nodeNum - realK - 1; i++){
            ptr = ptr.next;
        }
        ListNode newHead = ptr.next;
        ptr.next = null;
        return newHead;
    }
}
// @lc code=end


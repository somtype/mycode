/*
 * @lc app=leetcode.cn id=147 lang=java
 *
 * [147] 对链表进行插入排序
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
    public ListNode insertionSortList(ListNode head) {
        ListNode preHead = new ListNode(Integer.MIN_VALUE);
        preHead.next = head;
        ListNode ptr = preHead;
        while (ptr.next != null) {
            if (ptr.next.val < ptr.val) {
                ListNode temp = ptr.next;
                ptr.next = ptr.next.next;
                ListNode ptr2 = preHead;
                while (ptr2.next != ptr.next){
                    if(temp.val < ptr2.next.val){
                        temp.next = ptr2.next;
                        ptr2.next = temp;
                        break;
                    }
                    ptr2 = ptr2.next;
                }
            }
            else{
                ptr = ptr.next;
            }
        }
        return preHead.next;
    }
}
// @lc code=end

/*
 * @lc app=leetcode.cn id=21 lang=java
 *
 * [21] 合并两个有序链表
 *
 * https://leetcode-cn.com/problems/merge-two-sorted-lists/description/
 *
 * algorithms
 * Easy (66.73%)
 * Likes:    1992
 * Dislikes: 0
 * Total Accepted:    747.8K
 * Total Submissions: 1.1M
 * Testcase Example:  '[1,2,4]\n[1,3,4]'
 *
 * 将两个升序链表合并为一个新的 升序 链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：l1 = [1,2,4], l2 = [1,3,4]
 * 输出：[1,1,2,3,4,4]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：l1 = [], l2 = []
 * 输出：[]
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：l1 = [], l2 = [0]
 * 输出：[0]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 两个链表的节点数目范围是 [0, 50]
 * -100 
 * l1 和 l2 均按 非递减顺序 排列
 * 
 * 
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
    public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
        ListNode l3 = new ListNode();
        ListNode l1next = l1, l2next = l2, l3next = l3;
        while(l1next != null && l2next != null){
            if(l1next.val < l2next.val){
                ListNode node = new ListNode(l1next.val);
                l3next.next = node;
                l3next = node;
                l1next = l1next.next;
            }
            else{
                ListNode node = new ListNode(l2next.val);
                l3next.next = node;
                l3next = node;
                l2next = l2next.next;
            }
        }
        while(l1next != null){
            ListNode node = new ListNode(l1next.val);
            l3next.next = node;
            l3next = node;
            l1next = l1next.next;
        }
        while(l2next != null){
            ListNode node = new ListNode(l2next.val);
            l3next.next = node;
            l3next = node;
            l2next = l2next.next;
        }
        l3 = l3.next;
        return l3;
    }
}
// @lc code=end


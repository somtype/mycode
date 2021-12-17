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
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    ListNode globalHead;
    public TreeNode sortedListToBST(ListNode head) {
        globalHead = head;
        int length = getListLength(head);
        return build(1, length);
    }
    public int getListLength(ListNode head){
        int length = 0;
        while(head != null)
        {
            ++length;
            head = head.next;
        }
        return length;
    } 
    public TreeNode build(int left, int right){
        if(left > right)
        {
            return null;
        }
        TreeNode root = new TreeNode();
        int middle = left + (right - left)/2;
        root.left = build(left, middle - 1);
        root.val = globalHead.val;
        globalHead = globalHead.next;
        root.right = build(middle + 1, right);
        return root;
    }
}
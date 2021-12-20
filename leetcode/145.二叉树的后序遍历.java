/*
 * @lc app=leetcode.cn id=145 lang=java
 *
 * [145] 二叉树的后序遍历
 */

// @lc code=start
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
	List<Integer> result = new LinkedList<Integer>();
    public List<Integer> postorderTraversal(TreeNode root) {
		travel(root);
		return result;
    }
	public void travel(TreeNode root){
		if(root == null){
			return;
		}
		travel(root.left);
		travel(root.right);
		result.add(root.val);
	}
}
// @lc code=end


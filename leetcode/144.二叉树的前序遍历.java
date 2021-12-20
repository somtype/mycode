/*
 * @lc app=leetcode.cn id=144 lang=java
 *
 * [144] 二叉树的前序遍历
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
    public List<Integer> preorderTraversal(TreeNode root) {
		travel(root);
		return result;
    }
	public void travel(TreeNode root){
		if(root == null){
			return;
		}
		result.add(root.val);
		travel(root.left);
		travel(root.right);
	}
}
// @lc code=end


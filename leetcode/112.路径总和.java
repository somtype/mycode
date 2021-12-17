/*
 * @lc app=leetcode.cn id=112 lang=java
 *
 * [112] 路径总和
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
    public boolean hasPathSum(TreeNode root, int targetSum) {
        return check(root, targetSum, 0);
    }
    public boolean check(TreeNode root, int targetSum, int currSum){
        if(root == null){
            return false;
        }
        currSum += root.val;
        if(root.left == null && root.right == null){
            return currSum == targetSum;
        }
        return check(root.left, targetSum, currSum) || check(root.right, targetSum, currSum);
    }
}
// @lc code=end


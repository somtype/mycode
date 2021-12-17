/*
 * @lc app=leetcode.cn id=99 lang=java
 *
 * [99] 恢复二叉搜索树
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
    public void recoverTree(TreeNode root) {
        List<Integer> nums = new ArrayList<Integer>();
        inorder(root,nums);
        int x, y;
        x = y = 0;
        boolean flag = true;
        for(int i = 0; i < nums.size() - 1; ++i){
            if(nums.get(i) > nums.get(i+1)){
               if(flag == true){
                   flag = false;
                   x = i;
                   y = i + 1;
               }
               else{
                   y = i + 1;
               }
            }
        }
        recover(root, 2, nums.get(x), nums.get(y));
    }
    public void inorder(TreeNode root, List<Integer> nums){
        if(root == null){
            return;
        }
        inorder(root.left, nums);
        nums.add(root.val);
        inorder(root.right, nums);
        return;
    }
    public void recover(TreeNode root, int count, int x, int y){
        if(root != null){
            if(root.val == x || root.val == y){
                root.val = (root.val == x ? y : x);
                if(--count == 0)
                    return;
            }
        }
        recover(root.left, count, x, y);
        recover(root.right, count, x ,y);
    }
}
// @lc code=end


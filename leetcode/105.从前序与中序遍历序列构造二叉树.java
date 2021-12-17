/*
 * @lc app=leetcode.cn id=105 lang=java
 *
 * [105] 从前序与中序遍历序列构造二叉树
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
    Map<Integer, Integer> inorder_index;
    public TreeNode buildTree(int[] preorder, int[] inorder) {
        inorder_index = new HashMap<Integer, Integer>();
        int n = inorder.length;
        for (int i = 0; i < n; ++i) {
            inorder_index.put(inorder[i], i);
        }
        return build(preorder, inorder, 0, n - 1, 0, n - 1);
    }
    public TreeNode build(int[] preorder, int[] inorder, int preorder_left, int preorder_right,
                          int inorder_left, int inorder_right) {
        if (preorder_left > preorder_right || inorder_left > inorder_right) {
            return null;
        }
        TreeNode root = new TreeNode(preorder[preorder_left]);
        int inorder_root = inorder_index.get(root.val);
        int size_left_subtree = inorder_root - inorder_left;
        root.left = build(preorder, inorder, preorder_left + 1,
                          preorder_left + size_left_subtree, inorder_left, inorder_root - 1);
        root.right = build(preorder, inorder, preorder_left + size_left_subtree + 1,
                           preorder_right, inorder_root + 1, inorder_right);
        return root;
    }
}
// @lc code=end

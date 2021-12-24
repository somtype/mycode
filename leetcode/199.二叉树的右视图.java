/*
 * @lc app=leetcode.cn id=199 lang=java
 *
 * [199] 二叉树的右视图
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
    public List<Integer> rightSideView(TreeNode root) {
        List<Integer> result = new ArrayList<Integer>();
        check(root, result);
        return result;
    }
    public void check(TreeNode root, List<Integer> result) {
        //右子节点优先入队的层序遍历，没层第一个就是最右边的节点
        if(root == null){
            return;
        }
        Deque<TreeNode> deque = new LinkedList<TreeNode>();
        deque.offerLast(root);
        while(!deque.isEmpty()){
            int currLevelNum = deque.size();
            for(int i = 0; i < currLevelNum; ++i){
                TreeNode node = deque.pollFirst();
                if(node.right != null){
                    deque.offerLast(node.right);
                }
                if(node.left != null){
                    deque.offerLast(node.left);
                }
                if(i == 0){
                    result.add(node.val);
                }
            }
        }
    }
}
// @lc code=end


/*
 * @lc app=leetcode.cn id=116 lang=java
 *
 * [116] 填充每个节点的下一个右侧节点指针
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
    public int val;
    public Node left;
    public Node right;
    public Node next;

    public Node() {}

    public Node(int _val) {
        val = _val;
    }

    public Node(int _val, Node _left, Node _right, Node _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};
*/

class Solution {
    public Node connect(Node root) {
        if(root == null)
            return null;
        Node mostLeft = root;
        while(mostLeft.left != null){
            Node ptr = mostLeft;
            while(ptr != null){
                ptr.left.next = ptr.right;
                if(ptr.next != null){
                    ptr.right.next = ptr.next.left;
                }
                ptr = ptr.next;
            }
            mostLeft = mostLeft.left;
        }
        return root;
    }

    public void dfs(Node preNode, Node currNode) {
        if (currNode == null) {
            return;
        }
        if (currNode == preNode.left) {
            currNode.next = preNode.right;
        } else if (currNode == preNode.right) {
            if (preNode.next != null) {
                currNode.next = preNode.next.left;
            } else {
                currNode.next = null;
            }
        }
        dfs(currNode, currNode.left);
        dfs(currNode, currNode.right);
    }
}
// @lc code=end

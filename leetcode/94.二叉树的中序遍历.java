class Solution {
	public List<Integer> inorderTraversal(TreeNode root) {
		List<Integer> result = new ArrayList<Integer>();
		inorder(root,result);
		return result;
	}
	public void inorder(TreeNode root, List<Integer> result){
		if(root == null){
			return;
		}
		inorder(root.left, result);
		result.add(root.val);
		inorder(root.right, result);
	}
}

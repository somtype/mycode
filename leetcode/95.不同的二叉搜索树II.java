class Solution {
    public List<TreeNode> generateTrees(int n) {
        if (n == 0)
            return null;
        List<TreeNode> result = generateTrees(1, n);
        return result;
    }
    public List<TreeNode> generateTrees(int start, int end) {
        List<TreeNode> allTrees = new ArrayList<TreeNode>();
        if (start > end) {
            allTrees.add(null);
            return allTrees;
        }
        for (int i = start; i <= end; i++) {
            List<TreeNode> leftTrees =
                generateTrees(start, i - 1); //生成所有左子树
            List<TreeNode> rightTrees =
                generateTrees(i + 1, end); //生成所有右子树
            for (TreeNode left : leftTrees) {
                for (TreeNode right : rightTrees) {
                    TreeNode currTree = new TreeNode(i, left, right);
                    allTrees.add(currTree);
                }
            }
        }
        return allTrees;
    }
}

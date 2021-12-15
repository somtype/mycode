class Solution {
    public int numTrees(int n) {
        int[] s = new int[n + 1];
        s[0] = s[1] = 1;
        for (int length = 2; length <= n; length++) {
            for (int i = 1; i <= length; i++) {
                s[length] += s[i - 1] * s[length - i];
            }
        }
        return s[n];
    }
}

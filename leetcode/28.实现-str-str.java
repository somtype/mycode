/*
 * @lc app=leetcode.cn id=28 lang=java
 *
 * [28] 实现 strStr()
 */

// @lc code=start
class Solution {
    public int strStr(String haystack, String needle) {
		if(needle.length() == 0){
			return 0;
		}
		int i, j, n, m;
		i = j = 0;
		n = haystack.length();
		m = needle.length();
		int[] next = new int[m];
		int k = -1;
		next[0] = -1;
		while(j < m - 1){
			if(k == -1 || needle.charAt(j) == needle.charAt(k)){
				++j; ++k;
				if(needle.charAt(j) == needle.charAt(k))
					next[j] = next[k];
				else
					next[j] = k;
			}
			else{
				k = next[k];
			}
		}
		i = j = 0;
		while(i < n && j < m){
			if(j == -1 || haystack.charAt(i) == needle.charAt(j)){
				++i; ++j;
			}
			else{
				j = next[j];
			}
		}
		if(j == m){
			return i - m;
		}
		return -1;
    }
}
// @lc code=end


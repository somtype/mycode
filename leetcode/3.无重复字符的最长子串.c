/*
 * @lc app=leetcode.cn id=3 lang=c
 *
 * [3] 无重复字符的最长子串
 *
 * https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/description/
 *
 * algorithms
 * Medium (34.72%)
 * Likes:    3786
 * Dislikes: 0
 * Total Accepted:    520.7K
 * Total Submissions: 1.5M
 * Testcase Example:  '"abcabcbb"'
 *
 * 给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。
 * 
 * 示例 1:
 * 
 * 输入: "abcabcbb"
 * 输出: 3 
 * 解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
 * 
 * 
 * 示例 2:
 * 
 * 输入: "bbbbb"
 * 输出: 1
 * 解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。
 * 
 * 
 * 示例 3:
 * 
 * 输入: "pwwkew"
 * 输出: 3
 * 解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
 * 请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。
 * 
 * 
 */

// @lc code=start

int max(int a,int b){
    if(a>b) return a;
    else    return b;
}
int lengthOfLongestSubstring(char * s){
    int Map[128];
    int start=0,end=0,maxLen=1,sLen=strlen(s);
    for(int i=0;i<128;++i)
        Map[i]=-1;
    Map[s[start]]=start;
    if(sLen==0)
        return 0;
        else{
    while(end<sLen-1){
        end++;
        if(Map[s[end]]<start){
            Map[s[end]]=end;
        }
        else{
            start=Map[s[end]]+1;
            Map[s[end]]=end;
        }
        maxLen=max(maxLen,end-start+1);
    }
    return maxLen;
        }
}


// @lc code=end


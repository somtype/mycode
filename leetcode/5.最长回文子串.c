/*
 * @lc app=leetcode.cn id=5 lang=c
 *
 * [5] 最长回文子串
 */

// @lc code=start

char* longestPalindrome(char* s) {
    char dp[1000][1000];
    char res[1000];
    memset(dp, 0, sizeof(dp));
    memset(res, 0, sizeof(res));
    int length = strlen(s);
    for (int l = 0; l < length; l++) {
        for (int i = 0; i + l < length; i++) {
            int j = i + l;
            if (l == 0)
                dp[i][j] = 1;
            else if (l == 1)
                dp[i][j] = (s[i] == s[j]);
            else
                dp[i][j] = dp[i + 1][j - 1] && (s[i] == s[j]);
            if (dp[i][j] && l + 1 > strlen(res)) {
                int k;
                for (k = 0; k < l + 1; k++)
                    res[k] = s[k + i];
                res[k] = '\0';
            }
        }
    }
    return res;
}
// @lc code=end

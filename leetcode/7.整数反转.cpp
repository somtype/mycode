/*
 * @lc app=leetcode.cn id=7 lang=cpp
 *
 * [7] 整数反转
 */

// @lc code=start
class Solution {
  public:
    int reverse(long long int x) {
        long long int res = 0;
        while (x != 0) {
            int mod = x % 10;
            x /= 10;
            res *= 10;
            res += mod;
        }
        if (x < -2e21 || x >= 2e21) return 0;
        return res;
    }
};
// @lc code=end

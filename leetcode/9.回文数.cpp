/*
 * @lc app=leetcode.cn id=9 lang=cpp
 *
 * [9] 回文数
 */

// @lc code=start
#include <iostream>
using namespace std;
class Solution {
  public:
    bool isPalindrome(int x) {
        if (x < 0 || x % 10 == 0 && x != 0) return false;
        int reversed_num = 0;
        while (x > reversed_num) {
            reversed_num *= 10;
            reversed_num += x % 10;
            x /= 10;
        }
        return x == reversed_num || x == reversed_num / 10;
    }
};
// @lc code=end

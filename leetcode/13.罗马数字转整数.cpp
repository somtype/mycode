/*
 * @lc app=leetcode.cn id=13 lang=cpp
 *
 * [13] 罗马数字转整数
 */

// @lc code=start
#include <iostream>
#include <map>
class Solution {
  public:
    int romanToInt(std::string s) {
        std::map<char, int> values = {
            { 'I', 1 },
            { 'V', 5 },
            { 'X', 10 },
            { 'L', 50 },
            { 'C', 100 },
            { 'D', 500 },
            { 'M', 1000 }
        };
        int result = 0;
        std::string::iterator iter1 = s.begin();
        for (; iter1 < s.end(); iter1++) {
            if (values[*iter1] < values[*(iter1 + 1)])
                result -= values[*iter1];
            else
                result += values[*iter1];
        }
        return result;
    }
};
// @lc code=end

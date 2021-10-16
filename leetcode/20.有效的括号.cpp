/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 */

// @lc code=start
#include <iostream>
#include <stack>
#include <map>
class Solution {
  public:
    bool isValid(std::string s) {
        std::map<char, char> lover = {
            {'(',')'},
            {'[',']'},
            {'{','}'}
        };
        std::stack<char> pairs;
        for (std::string::iterator iter_s = s.begin(); iter_s < s.end(); iter_s++) {
            if (*iter_s == '(' || *iter_s == '[' || *iter_s == '{') {
                pairs.push(*iter_s);
            } else {
                if (pairs.empty()) {
                    return false;
                }
                char ch = pairs.top();
                pairs.pop();
                if (lover[ch] != *iter_s){
                    return false;
                }
            }
        }
        if (pairs.empty())
            return true;
        return false;
    }
};
// @lc code=end

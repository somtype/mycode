/*
 * @lc app=leetcode.cn id=14 lang=cpp
 *
 * [14] 最长公共前缀
 */

// @lc code=start
#include <iostream>
#include <vector>
class Solution {
  public:
    std::string longestCommonPrefix(std::vector<std::string>& strs) {
        //存下每个字符串的迭代器，i是字符串和他的迭代器的“关联”
        std::vector<std::string::iterator> iters;
        for (int i = 0; i < strs.size(); i++) {
            iters.push_back(strs[i].begin());
        }
        std::string result = "";
        while (1) {
            //只有所有迭代器所指向的值都相等，公共前缀才能加长，否则输出结果
            for (int i = 0; i < iters.size(); i++) {
                if (iters[i] >= strs[i].end() || *iters[i] != *iters[0])
                    return result;
            }
            //公共前缀加长，所有迭代器指向下一个值
            result += *iters[0];
            for (int i = 0; i < iters.size(); i++) {
                iters[i]++;
            }
        }
    }
};
// @lc code=end

/*
 * @lc app=leetcode.cn id=11 lang=cpp
 *
 * [11] 盛最多水的容器
 * 题解：双指针，太nb了
 */

// @lc code=start
class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int maxCap = 0
        while(left < right){
            maxCap = max(maxCap, (right - left) * min(height[left], height[right]));
            if(height[left] < height[right]){
                left ++;
            }
            else{
                right --;
            }
        }
        return maxCap;
    }
};
// @lc code=end


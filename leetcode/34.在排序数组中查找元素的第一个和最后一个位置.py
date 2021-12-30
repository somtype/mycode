#
# @lc app=leetcode.cn id=34 lang=python3
#
# [34] 在排序数组中查找元素的第一个和最后一个位置
#

# @lc code=start
class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        result = [-1, -1]
        for i in range(len(nums)):
            if nums[i] > target:
                break
            if nums[i] == target:
                if result[0] == -1:
                    result[0] = result[1] = i
                else:
                    result[1] = i
        return result
    
# @lc code=end


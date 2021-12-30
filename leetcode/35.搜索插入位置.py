#
# @lc app=leetcode.cn id=35 lang=python3
#
# [35] 搜索插入位置
#

# @lc code=start
class Solution:
    result = -1
    def searchInsert(self, nums: List[int], target: int) -> int:
        self.binary_search(nums, target, 0, len(nums))
        return self.result

    def binary_search(self, nums: list, target: int, left, right):
        if left >= right:
            self.result = left
            return;
        middle = left + (right - left) // 2;
        if nums[middle] == target:
            self.result = middle
            return;
        elif nums[middle] < target:
            self.binary_search(nums, target, middle + 1, right)
        else:
            self.binary_search(nums, target, left, middle)

# @lc code=end


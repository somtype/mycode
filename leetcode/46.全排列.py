#
# @lc app=leetcode.cn id=46 lang=python3
#
# [46] 全排列
#

# @lc code=start
class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        result = []
        curr = []
        status = [0] * 21
        def solve(n: int) -> None:
            if n >= len(nums):
                result.append(curr.copy())
                return
            for num in nums:
                if status[num + 10] == 1:
                    continue
                curr.append(num)
                status[num + 10] = 1
                solve(n + 1)
                curr.pop()
                status[num + 10] = 0
            return
        solve(0)
        return result
# @lc code=end


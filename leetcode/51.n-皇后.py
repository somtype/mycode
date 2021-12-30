#
# @lc app=leetcode.cn id=51 lang=python3
#
# [51] N 皇后
#

# @lc code=start
class Solution:
    def solveNQueens(self, n: int) -> List[List[str]]:
        result = []
        res = []
        def is_valid(res: list[str], curr: int, i: int) -> bool:
            for j in range(len(res)):
                if(res[j][i] == 'Q'):
                    return False
                try:
                    if res[j][i + curr - j] == 'Q':
                        return False
                except:
                    pass
                try:
                    if res[j][i - (curr - j)] == 'Q':
                        return False
                except:
                    pass
            return True

        def solve(n: int, curr: int, res: list) -> None:
            if curr >= n:
                result.append(res.copy())
                return
            for i in range(n):
                if is_valid(res, curr, i):
                    line = ['.'] * n
                    line[i] = 'Q'
                    line = ''.join(line)
                    res.append(line)
                    print(res)
                    solve(n, curr + 1, res)
                    res.pop()
            return
        solve(n, 0, res)
        return result
# @lc code=end


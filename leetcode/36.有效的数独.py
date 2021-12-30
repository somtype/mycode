#
# @lc app=leetcode.cn id=36 lang=python3
#
# [36] 有效的数独
#

# @lc code=start
class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        lines = [[0] * 9 for _ in range(9)]
        cols = [[0] * 9 for _ in range(9)]
        blocks = [[0] * 9 for _ in range(9)]
        for i in range(9):
            for j in range(9):
                curr = board[i][j]
                if lines[i][curr] != 0:
                    return False
                lines[i][curr] = 1
                if cols[j][curr] != 0:
                    return False
                cols[j][curr] = 1
                if blocks[3 * i // 3 + j // 3 - 1][curr] != 0:
                    return False
                blocks[3 * (i // 3) + j // 3 - 1][curr] = 1
        return True

# @lc code=end

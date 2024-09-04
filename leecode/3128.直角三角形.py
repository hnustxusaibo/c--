#
# @lc app=leetcode.cn id=3128 lang=python3
#
# [3128] 直角三角形
#

# @lc code=start
class Solution:
    def numberOfRightTriangles(self, grid: List[List[int]]) -> int:
        row  = len(grid)
        column  = len(grid[0])
        row_sum = [0] * row
        column_sum = [0] * column

        for i in range(row):
            for j in range(column):
                row_sum[i] += grid[i][j]
                column_sum[j] += grid[i][j]
        ans = 0
        for i in range(row):
            for j in range(column):
                if grid[i][j]:
                    ans += (row_sum[i] - 1) * (column_sum[j] - 1)
        return ans
        


# @lc code=end


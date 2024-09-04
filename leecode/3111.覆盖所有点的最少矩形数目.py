#
# @lc app=leetcode.cn id=3111 lang=python3
#
# [3111] 覆盖所有点的最少矩形数目
#

# @lc code=start
class Solution:
    def minRectanglesToCoverPoints(self, points: List[List[int]], w: int) -> int:
        x_set = set()
        for point in points:
            x_set.add(point[0])
        ans = 0
        limit = -1 
        for x in sorted(x_set):
            print(f"x={x}")
            if x > limit:
                ans += 1
                limit = x + w
                print(f"limit={limit}")
        return ans

# @lc code=end


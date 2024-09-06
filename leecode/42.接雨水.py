#
# @lc app=leetcode.cn id=42 lang=python3
#
# [42] 接雨水
#

# @lc code=start
class Solution:
    def trap(self, height: List[int]) -> int:
        ans = 0
        monotonic_stack = []
        for i in range(len(height)):
            while monotonic_stack and height[monotonic_stack[-1]] < height[i]:
                top_index = monotonic_stack.pop()
                if not monotonic_stack:
                    break
                w = i - monotonic_stack[-1] - 1
                h = min(height[monotonic_stack[-1]], height[i]) - height[top_index]
                ans += w * h
                print(f"i={i},top={top_index},w={w},h={h}")
            monotonic_stack.append(i)
        return ans
                
                

# @lc code=end


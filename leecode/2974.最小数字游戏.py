#
# @lc app=leetcode.cn id=2974 lang=python3
#
# [2974] 最小数字游戏
#

# @lc code=start
class Solution:
    def numberGame(self, nums: List[int]) -> List[int]:
        nums.sort()
        for i in range(int(len(nums)/2)):
            nums[i*2],nums[i*2+1] = nums[i*2+1],nums[i*2]
        return nums
# @lc code=end


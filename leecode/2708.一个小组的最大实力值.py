#
# @lc app=leetcode.cn id=2708 lang=python3
#
# [2708] 一个小组的最大实力值
#

# @lc code=start
class Solution:
    def maxStrength(self, nums: List[int]) -> int:
        mi = nums[0]
        ma = nums[0]
        for i in range(1, len(nums)):
            num = nums[i]
            tmp_mi = min(mi, num, mi * num, ma * num)
            ma = max(ma, num, mi * num, ma * num)
            mi = tmp_mi
            print(f"num={num}, mi = {mi}, ma = {ma}")
        return ma
# @lc code=end


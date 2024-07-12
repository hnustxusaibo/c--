#
# @lc app=leetcode.cn id=2972 lang=python3
#
# [2972] 统计移除递增子数组的数目 II
#


# @lc code=start
class Solution:
    def incremovableSubarrayCount(self, nums: List[int]) -> int:
        n = len(nums)

        l = 0
        r = n - 1

        while l < n - 1 and nums[l] < nums[l + 1]:
            l += 1

        if l == r:
            return int((n * n + n) / 2)
        
        while r > 0 and nums[r] > nums[r - 1]:
            r -= 1

        ans = 1 + (l + 1) + (n - r)
        print(f"ans = {ans}")
        import bisect

        while l >= 0:
            idx = bisect.bisect_right(nums[r:], nums[l]) + r
            if idx >= n:
                l -= 1
                continue
            ans += n - idx
            print(f"nums[{l}]={nums[l]},nums[{idx}] = {nums[idx]},ans = {ans}")
            l -= 1
        return int(ans)


# @lc code=end

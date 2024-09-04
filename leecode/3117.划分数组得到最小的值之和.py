#
# @lc app=leetcode.cn id=3117 lang=python3
#
# [3117] 划分数组得到最小的值之和
#

# @lc code=start
class Solution:
    def minimumValueSum(self, nums: List[int], andValues: List[int]) -> int:
        nums_size = len(nums)
        andValues_size = len(andValues)
        dp = [[-2 for _ in range(nums_size + 2)] for _ in range(andValues_size + 2)]

        def slove(nums_item: int, andValues_item: int):
            print(f"nums_item={nums_item}, andValues_item={andValues_item}")
            if nums_item == nums_size and andValues_item == andValues_size:
                dp[nums_item][andValues_item] = 0
                return 0
            if nums_item >= nums_size or andValues_item >= andValues_size:
                dp[nums_item][andValues_item] = -1
                return -1
            
            if dp[nums_item][andValues_item] != -2:
                return dp[nums_item][andValues_item]
            
            mi = 1e9
            _tmp = nums[nums_item]
            for it in range(nums_item, nums_size):
                _tmp &= nums[it]
                print(f"it={it},_tmp={_tmp}")
                if _tmp == andValues[andValues_item]:
                    v = slove(it + 1, andValues_item + 1)
                    if v != -1:
                        mi = min(mi, v + nums[it])
                
                if it > nums_size - (andValues_size - andValues_item):
                    break
            if mi == 1e9:
                dp[nums_item][andValues_item] == -1
            else:
                dp[nums_item][andValues_item]  = mi
            print(f"dp[{nums_item}][{andValues_item}] = {dp[nums_item][andValues_item]}")
            return dp[nums_item][andValues_item]

        return slove(0, 0)

# @lc code=end


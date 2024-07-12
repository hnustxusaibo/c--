#
# @lc app=leetcode.cn id=3115 lang=python3
#
# [3115] 质数的最大距离
#

# @lc code=start

def is_prime(n):
    if n <= 1:
        return False
    for i in range(2, int(n**0.5) + 1):
        if n % i == 0:
            return False
    return True

prime_list =  [num for num in range(2, 100) if is_prime(num)]

class Solution:
    def maximumPrimeDifference(self, nums: List[int]) -> int:
        first_i = -1
        last_i = -1
        for i,num in enumerate(nums):
            if num in prime_list:
                if first_i == -1 :
                    first_i = i
                    last_i = i
                else:
                    last_i = i
        return last_i - first_i 
# @lc code=end


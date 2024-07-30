#
# @lc app=leetcode.cn id=2961 lang=python3
#
# [2961] 双模幂运算
#

# @lc code=start
class Solution:
    def getGoodIndices(self, variables: List[List[int]], target: int) -> List[int]:
        def binary_exponentiation(x: int, y: int ,mod: int):
            ans = 1
            x %= mod
            while y:
                if y & 1:
                    ans = (ans * x) % mod
                y >>= 1
                x = (x * x) % mod
            return ans
        ans_list = []
        for i, variable in enumerate(variables):
            a, b, c, m = variable
            temp = binary_exponentiation(a, b, 10)
            ans = binary_exponentiation(temp, c, m)
            if ans == target:
                ans_list.append(i)
        return ans_list



# @lc code=end


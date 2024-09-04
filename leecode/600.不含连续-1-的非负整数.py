#
# @lc app=leetcode.cn id=600 lang=python3
#
# [600] 不含连续1的非负整数
#

# @lc code=start
def compute_dp(n):
    # 初始化 dp 数组，大小为 (n+1) x 2
    dp = [[0 for _ in range(2)] for _ in range(n+1)]
    
    # 设置初始状态
    dp[1][0] = 1
    dp[1][1] = 1
    
    # 递推计算 dp 数组
    for i in range(1, n):
        dp[i+1][0] = dp[i][0] + dp[i][1]
        dp[i+1][1] = dp[i][0]
    
    return dp
dp = compute_dp(32)
class Solution:
    def findIntegers(self, n: int) -> int:
        print(f"findIntegers({n})")
        if n == 0:
            return 1
        if n == 1:
            return 2
        

        bin_n = bin(n)[2:]
        bin_len = len(bin_n)
        # b[0] = 0
        ans = dp[bin_len][0]
        # b[0] = 1 b[1] = 0
        if bin_n[1] == '1':
            ans += self.findIntegers((1 << (bin_len - 2)) - 1 )
        else:
            ans += self.findIntegers(int('00' + bin_n[2:], 2))
        print(f"n={n},ans={ans}")
        return ans

        

# @lc code=end


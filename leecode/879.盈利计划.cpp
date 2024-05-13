/*
 * @lc app=leetcode.cn id=879 lang=cpp
 *
 * [879] 盈利计划
 *
 * https://leetcode.cn/problems/profitable-schemes/description/
 *
 * algorithms
 * Hard (54.51%)
 * Likes:    308
 * Dislikes: 0
 * Total Accepted:    31K
 * Total Submissions: 56.9K
 * Testcase Example:  '5\n3\n[2,2]\n[2,3]'
 *
 * 集团里有 n 名员工，他们可以完成各种各样的工作创造利润。
 * 
 * 第 i 种工作会产生 profit[i] 的利润，它要求 group[i] 名成员共同参与。如果成员参与了其中一项工作，就不能参与另一项工作。
 * 
 * 工作的任何至少产生 minProfit 利润的子集称为 盈利计划 。并且工作的成员总数最多为 n 。
 * 
 * 有多少种计划可以选择？因为答案很大，所以 返回结果模 10^9 + 7 的值。
 * 
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：n = 5, minProfit = 3, group = [2,2], profit = [2,3]
 * 输出：2
 * 解释：至少产生 3 的利润，该集团可以完成工作 0 和工作 1 ，或仅完成工作 1 。
 * 总的来说，有两种计划。
 * 
 * 示例 2：
 * 
 * 
 * 输入：n = 10, minProfit = 5, group = [2,3,5], profit = [6,7,8]
 * 输出：7
 * 解释：至少产生 5 的利润，只要完成其中一种工作就行，所以该集团可以完成任何工作。
 * 有 7 种可能的计划：(0)，(1)，(2)，(0,1)，(0,2)，(1,2)，以及 (0,1,2) 。
 * 
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 
 * 0 
 * 1 
 * 1 
 * profit.length == group.length
 * 0 
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    long long dp[105][105][105] = {{{0}}}; // 初始化三维数组 dp 为0   
    int mod = 1e9 + 7;
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {     
        int cnt = group.size();
        dp[0][0][0] = 1;
        for(int i=0; i<cnt ;i++)
            for(int j=0; j<=n; j++)
                for(int k=0; k<=minProfit; k++)
                    if(dp[i][j][k])
                    {
                        // printf("dp[%d][%d][%d]=%lld\n",i,j,k,dp[i][j][k]);
                        dp[i+1][j][k] += dp[i][j][k];    
                        dp[i+1][j][k] %= mod;  
                        if(j+group[i] <= n) {
                            dp[i+1][j+group[i]][min(k+profit[i],minProfit)] += dp[i][j][k];
                            dp[i+1][j+group[i]][min(k+profit[i],minProfit)] %= mod;  
                        }
                    }
        long long sum = 0;
        for(int j=0; j<=n; j++){
            // printf("dp[%d][%d][%d]=%lld\n",cnt,j,minProfit,dp[cnt][j][minProfit]);
            sum = (sum + dp[cnt][j][minProfit]) % mod;
        }
        return sum;
    }
};
// @lc code=end


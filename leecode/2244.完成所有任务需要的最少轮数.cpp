/*
 * @lc app=leetcode.cn id=2244 lang=cpp
 *
 * [2244] 完成所有任务需要的最少轮数
 */

// @lc code=start
class Solution {
   public:
    int minimumRounds(vector<int>& tasks) {
        std::unordered_map<int, int> countMap;
        // 统计每个数字出现的次数
        for (int num : tasks) {
            countMap[num]++;
        }

        int ans = 0;

        // 检查是否存在仅出现一次的数字
        for (const auto& pair : countMap) {
            if (pair.second == 1) {
                return -1;
            }
            ans += (pair.second + 2) / 3;
        }
        return ans;
    }
};
// @lc code=end

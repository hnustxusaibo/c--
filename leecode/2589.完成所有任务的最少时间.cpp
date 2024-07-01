/*
 * @lc app=leetcode.cn id=2589 lang=cpp
 *
 * [2589] 完成所有任务的最少时间
 */

// @lc code=start

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    static bool cmp(vector<int>& x, vector<int>& y) {
        return x[1] < y[1];
    }
    int run[2003];
    int sum(int start, int end) {
        int sum = 0;
        for (int i = start; i <= end; i++) sum += run[i];
        return sum;
    }
    int findMinimumTime(vector<vector<int>>& tasks) {
        for (int i = 0; i < 2003; i++) run[i] = 0;
        sort(tasks.begin(), tasks.end(), cmp);
        int ans = 0;
        for (int i = 0; i < tasks.size(); i++) {
            int start = tasks[i][0];
            int end = tasks[i][1];
            int dis = tasks[i][2];
            int total = sum(start, end);
            if (total >= dis) continue;
            int t = dis - total;
            while (t) {
                while (run[end] == 1) end--;
                run[end] = 1;
                printf("j=%d\n", end);
                ans++;
                t--;
            }
        }
        return ans;
    }
};
// int main(int argc, char const* argv[]) {
//     Solution s;
//     vector<vector<int>> tasks = {{2, 3, 1},
//                                  {4, 5, 1},
//                                  {1, 5, 2}};
//     s.findMinimumTime(tasks);
//     return 0;
// }
// @lc code=end

/*
 * @lc app=leetcode.cn id=2225 lang=cpp
 *
 * [2225] 找出输掉零场或一场比赛的玩家
 */

// @lc code=start

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int d[100005];
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        for (auto matche : matches) {
            d[matche[1]]++;
        }
    }
};
// @lc code=end

/*
 * @lc app=leetcode.cn id=1542 lang=cpp
 *
 * [1542] 找出最长的超赞子字符串
 */

// @lc code=start

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int BitCount2(int n) {
        int c = 0;
        for (c = 0; n; ++c) {
            n &= (n - 1);
        }
        return c;
    }
    int longestAwesome(string s) {
        int n = 1 << 10;
        std::vector<std::pair<int, int>> vec(n, std::make_pair(-1, -1));
        int tmp = 0;
        int ans = 0;
        for (int i = 0; i < s.size(); i++) {
            tmp ^= (1 << (s[i] - '0'));
            printf("i=%d,tmp=%d\n", i, tmp);
            if (vec[tmp].first == -1) {
                vec[tmp].first = vec[tmp].second = i;
            } else {
                vec[tmp].second = i;
            }
            if (tmp == 0 || tmp & (tmp - 1) == 0) ans = i + 1;
        }
        for (int i = 0; i < n; i++)
            for (int j = i; j < n; j++)
                if (vec[i].first != -1 && vec[j].first != -1) {
                    int t = i ^ j;
                    // printf("i=%X,j=%X,t=%X\n", i, j, t);
                    if (t == 0 || t & (t - 1) == 0) {
                        ans = max(ans, vec[i].second - vec[j].first);
                        ans = max(ans, vec[j].second - vec[i].first);
                        printf("i=%X,j=%X,ans=%d\n", i, j, ans);
                    }
                }
        return ans;
    }
};

// @lc code=end

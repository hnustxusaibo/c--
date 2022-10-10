#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
const int mod = 1e9 + 7;
const int N = 1e5 + 5;

class Solution
{
public:
    int dp[100005][2];

    int minSwap(vector<int> &nums1, vector<int> &nums2)
    {
        dp[0][0] = 0;
        dp[0][1] = 1;
        for (int i = 1; i < nums1.size(); i++)
        {
            if (min(nums1[i], nums2[i]) > max(nums1[i - 1], nums2[i - 1]))
            {
                dp[i][0] = min(dp[i - 1][0], dp[i - 1][1]);
                dp[i][1] = dp[i][0] + 1;
            }
            else if (nums1[i] > max(nums1[i - 1], nums2[i - 1]))
            {
                if (nums2[i] > nums2[i - 1])
                {
                    dp[i][0] = dp[i - 1][0];
                    dp[i][1] = dp[i - 1][1] + 1;
                }
                else
                {
                    dp[i][1] = dp[i - 1][0] + 1;
                    dp[i][0] = dp[i - 1][1];
                }
            }
            else if (nums2[i] > max(nums1[i - 1], nums2[i - 1]))
            {
                if (nums1[i] > nums1[i - 1])
                {
                    dp[i][0] = dp[i - 1][0];
                    dp[i][1] = dp[i - 1][1] + 1;
                }
                else
                {
                    dp[i][1] = dp[i - 1][0] + 1;
                    dp[i][0] = dp[i - 1][1];
                }
            }
            printf("dp[%d][0]=%d,dp[%d][1]=%d\n", i, dp[i][0], i, dp[i][1]);
        }
        int n = nums1.size();
        return min(dp[n - 1][0], dp[n - 1][1]);
    }
};
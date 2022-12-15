#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
const int mod = 1e9 + 7;
const int MAX = 2e9 + 7;
const int N = 2e4 + 5;

double dp[101][101][101], sum[101];

double largestSumOfAverages(vector<int> &nums, int k)
{
    int n = nums.size();
    int s = 0;
    for (int i = 0; i <= n; i++)
        sum[i + 1] = sum[i] + nums[i];

    for (int i = 0; i < n; i++)
    {
        dp[i][i][1] = nums[i];
        for (int j = i + 1; j < n; j++)
            dp[i][j][1] = (sum[j + 1] - sum[i]) / (j - i + 1);
    }
    for (int z = 2; z <= k; z++)
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++)
            {
            }
    return 0.0;
}
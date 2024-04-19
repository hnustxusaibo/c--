#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
const int mod = 1e9 + 7;
const int MAX = 2e9 + 7;
const int N = 50 + 5;

ll dp[N][N][N], mp[N][N], sum[N][N];

int sum_a_b(int ax, int ay, int bx, int by)
{
    return sum[ax][ay] + sum[bx][by] - sum[ax][by] - sum[bx][ay];
}

int ways(vector<string> &pizza, int K)
{
    int n = pizza.size();
    int m = pizza[0].size();
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            if (pizza[i][j] == 'A')
                mp[i][j] = 1;
            sum[i][j] = mp[i][j] + (j == 0 ? 0 : sum[i][j - 1]) + (i == 0 ? 0 : sum[i - 1][j]) - (i == 0 && j == 0 ? 0 : sum[i][j]);
        }
    ll ans;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            for (int k = 1; k <= K; k++)
            {
                dp[i][j][k] = 0;
                for (int ii = 0; ii < i; ii++)
                    if (sum[ii][j] < sum[i][j])
                        dp[i][j][k] += dp[ii][j][k - 1];
                for (int jj = 0; jj < find(i, j, 1); jj++)
                    if (sum[i][jj] < sum[i][j])
                        dp[i][j][k] += dp[i][jj][k - 1];
                dp[i][j][k] %= mod;
                if (k == K && dp[i][j] < dp[n - 1][m - 1])
                    ans += dp[i][j][k];
            }
    return ans % mod;
}
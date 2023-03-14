#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
const int mod = 1e9 + 7;
const int MAX = 2e9 + 7;
const int N = 1e3 + 5;

int dp[101][101][2];
int stoneGameII(vector<int> &piles)
{
    int ans = 0;
    int n = piles.size();
    dp[0][1][0] = 1;
    for (int i = 0; i < n; i++)
        for (int j = 1; j < n; j++)
            for (int k = 0; k < 2; k++)
                if (dp[i][j][k])
                {
                    int sum = piles[i];
                    printf("  dp[%d][%d][%d]=%d\n", i, j, k, dp[i][j][k]);
                    for (int z = 1; z <= j * 2 && i + z <= n; z++)
                    {
                        int tmp = dp[i + z][max(j, z)][k ^ 1];
                        tmp = max(tmp, dp[i][j][k] + (k ? 0 : sum));
                        ans = max(ans, tmp);
                        dp[i + z][max(j, z)][k ^ 1] = tmp;
                        printf("dp[%d][%d][%d]=%d\n", i + z, max(j, z), k ^ 1, tmp);
                        if (i + z < n)
                            sum += piles[i + z];
                    }
                }
    return ans - 1;
}

int main(int argc, char const *argv[])
{
    vector<int> vec = {2, 7, 9, 4, 4};
    cout << stoneGameII(vec) << endl;
    return 0;
}
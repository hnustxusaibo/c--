#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;

const int mod = 1e9 + 7;
long long dp[1002][1002];
bool f[1002][1002];
int dfs(int n, int k)
{
    long ans = 0;
    for (int i = 0; i <= n && i <= k; i++)
    {
        if (f[n - 1][k - 1])
            ans = (ans + dp[n - 1][k - i]) % mod;
        else
            ans = (ans + dfs(n - 1, k - i)) % mod;
    }
    dp[n][k] = ans;
    f[n][k] = 1;
    return ans;
}

int kInversePairs(int n, int k)
{
    for (int i = 0; i <= n; i++)
        f[0][i] = 1;
    return dfs(n, k);
}

int main()
{
    printf("Hello World!\n");
    cout << "Jell" << endl;
    return 0;
}
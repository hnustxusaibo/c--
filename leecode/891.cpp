#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
const int mod = 1e9 + 7;
const int MAX = 2e9 + 7;
const int N = 2e4 + 5;

int quickPower(int x, int y, int mod)
{
    int ans = 1;
    while (y)
    {
        if (y & 1)
            ans = (1ll * ans * x) % mod;
        y >>= 1;
        x = (1ll * x * x) % mod;
    }
    return ans;
}

int sumSubseqWidths(vector<int> &nums)
{
    int ans = 0;
    sort(nums.begin(), nums.end());
    int n = nums.size();
    for (int i = 1; i <= n; i++)
    {
        ans = (ans + 1ll * (nums[n - i] - nums[i - 1]) * (quickPower(2, n, mod) - 1)) % mod;
    }
    return (ans + mod) % mod;
}
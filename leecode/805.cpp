#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

const int mod = 1e5;
const int N = 1e3 + 5;

bool dp[33][10005];

bool splitArraySameAverage(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    int sum = 0, n;
    n = nums.size();
    for (auto x : nums)
        sum += x;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j >= 0; j--)
        {
            for (int s = 0; s < sum; s++)
                if (dp[j][s])
                {
                    int nn = j + 1;
                    int ssum = s + nums[i];
                    printf("nn=%d,ssum=%d\n", nn, ssum);
                    if (n != nn && 1ll * (sum - ssum) * nn == 1ll * ssum * (n - nn))
                        return true;
                    dp[nn][ssum] = true;
                }
        }
    }
    return false;
}

int main()
{

    return 0;
}
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
const int mod = 1e9 + 7;
const int N = 1e3 + 5;

int dp[2002][30];

int distinctSubseqII(string s)
{
    for (int i = 0; i < s.size(); i++)
    {
        int c = s[i] - 'a';
        long long sum = 0;
        for (int j = 0; j < 26; j++)
            dp[i + 1][j] = dp[i][j], sum = (sum + dp[i][j]) % mod;
        dp[i + 1][c] += sum;
        if (dp[i][c] == 0)
            dp[i + 1][c]++;
        for (int j = i - 1; j > 0; j--)
            if (s[j] == s[i])
            {
                long long sum = 0;
                for (int k = 0; k < 26; k++)
                    sum = (sum + dp[j - 1][k]) % mod;
                dp[i + 1][c] = (dp[i + 1][c] - sum + mod) % mod;
                break;
            }
    }
    long long sum = 0;
    int i = s.size();
    for (int j = 0; j < 26; j++)
        sum = (sum + dp[i][j]) % mod;
    return (int)sum;
}

int main()
{
    distinctSubseqII("ada");
    return 0;
}
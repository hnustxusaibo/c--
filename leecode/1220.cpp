#include <bits/stdc++.h>

using namespace std;


typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;
const int mod = 1e9+7;
const int MAX = 2e9+7;
const int N = 2e4+5;

int dp[N][5];

int countVowelPermutation(int n) {
    for(int i=0;i<5;i++) dp[1][i]=1;
    for(int i=1;i<n;i++){
        dp[i+1][1] = (dp[i+1][1] + dp[i][0])%mod;

        dp[i+1][0] = (dp[i+1][0] + dp[i][1])%mod;
        dp[i+1][2] = (dp[i+1][2] + dp[i][1])%mod;

        dp[i+1][0] = (dp[i+1][0] + dp[i][2])%mod;
        dp[i+1][1] = (dp[i+1][1] + dp[i][2])%mod;
        dp[i+1][2] = (dp[i+1][2] + dp[i][2])%mod;
        dp[i+1][3] = (dp[i+1][3] + dp[i][2])%mod;

        dp[i+1][2] = (dp[i+1][2] + dp[i][3])%mod;
        dp[i+1][4] = (dp[i+1][4] + dp[i][3])%mod;

        dp[i+1][0] = (dp[i+1][0] + dp[i][4])%mod;
    }
    return  dp[n][0]+ dp[n][1]+ dp[n][2]+ dp[n][3]+ dp[n][4];
}
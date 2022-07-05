#include <bits/stdc++.h>

using namespace std;


typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;
const int mod = 1e9+7;
const int MAX = 2e9+7;
const int N = 2e4+5;
 int dp[N][3]; 
int minCost(vector<vector<int>>& costs) {
    int len = costs.size();
    dp[0][0] = costs[0][0];
    dp[0][1] = costs[0][1];
    dp[0][2] = costs[0][2];
    for(int i=1;i<len;i++){
        for(int j=0;j<3;j++) {
            dp[i][j] = min(dp[i-1][(j+1)%3],dp[i-1][(j+2)%3]) + costs[i][j];
        }
    }
    return min(dp[len-1][0],min(dp[len-1][1],dp[len-1][2]));
}
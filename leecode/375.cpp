#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;
const int mod = 1e9+7;
const int N = 1e3+5;

int dp[N][N];

int DP(int x,int y){
    if(dp[x][y]) return dp[x][y];
    if(x==y) {
        dp[x][y]==0;
        return 0;
    }
    if(x+1==y) {
        dp[x][y]==x;
        return x;
    }
    if(x+2==y) {
        dp[x][y]==x+1;
        return x+1;
    }
    int ans = 1e9;
    for(int i=x+1;i<y;i++){
        ans = min(ans,DP(x,i-1)+DP(i+1,y)+i);
    }
    dp[x][y]=ans;
    return ans;
}

int getMoneyAmount(int n) {
    cout << DP(1,n) << endl;
}

int main()
{
   
   return 0;
}
#include <bits/stdc++.h>

using namespace std;


typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;
const int mod = 1e9+7;
const int MAX = 2e9+7;
const int N = 2e4+5;

class Solution {
public:
    bool check(int x,int y,int n,vector<vector<int>>& grid){
        return x<n&&x>=0&&y<n&&y>=0&&grid[x][y]!=-1;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int dp[2][51][51]={-1};
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < 51; ++j) {
                for (int k = 0; k < 51; ++k) {
                    dp[i][j][k] = -1;
                }
            }
        }
        int n = grid.size();
        dp[0][0][0] = grid[0][0];
        for(int k=1;k<=2*(n-1);k++){
            bool flag = true;
            for(int i=0;i<=k&&i<n;i++)
            for(int x=0;x<=k&&x<n;x++){
                int j=k-i;
                int y=k-x;
                if(check(i,j,n,grid)&&check(x,y,n,grid)){
                    int ans = -1;
                    flag = false;
                    if(i>0&&x>0) ans = max(ans,dp[(k+1)%2][i-1][x-1]);
                    if(i>0&&y>0) ans = max(ans,dp[(k+1)%2][i-1][x]);
                    if(j>0&&x>0) ans = max(ans,dp[(k+1)%2][i][x-1]);
                    if(j>0&&y>0) ans = max(ans,dp[(k+1)%2][i][x]);
                    if(ans != -1) {
                        ans+=grid[i][j];
                        if(i!=x) ans+=grid[x][y];
                        dp[k%2][i][x]=ans;
                        printf("dp[%d][%d][%d][%d][%d]=%d\n",k,i,j,x,y,ans);
                    }
                }
            }
            if(flag) return 0;
        }
        return dp[2*(n-1)%2][n-1][n-1];
    }
};
[
[ 1,-1, 1, 1, 1, 1, 1, 1,-1, 1],
[ 1, 1, 1, 1,-1,-1, 1, 1, 1, 1],
[-1, 1, 1,-1, 1, 1, 1, 1, 1, 1],
[ 1, 1,-1, 1,-1, 1, 1, 1, 1, 1],
[-1, 1, 1, 1, 1, 1, 1, 1, 1, 1],
[-1,-1, 1, 1, 1,-1, 1, 1,-1, 1],
[ 1, 1, 1, 1, 1, 1, 1,-1, 1, 1],
[ 1, 1, 1, 1,-1, 1,-1,-1, 1, 1],
[ 1,-1, 1,-1,-1, 1, 1,-1, 1,-1],
[-1, 1,-1, 1,-1, 1, 1, 1, 1, 1]
]
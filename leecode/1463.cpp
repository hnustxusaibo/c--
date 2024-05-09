#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;
const int mod = 1e9+7;
const int N = 1e3+5;

class Solution {
public:
    int dp[2][71][71];
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int anss=0;
        for(int i=0;i<n;i++)
        for(int x=0;x<m&&x<=i;x++)
        for(int y=m-1;y>=0&&y>=m-i-1;y--){
            int ans = 0;
            for(int xx=x-1;xx<=x+1;xx++)
            for(int yy=y-1;yy<=y+1;yy++)
            if(xx>=0&&xx<m&&yy>=0&&yy<m)
            {
                printf("dp[%d][%d][%d]=%d\n",i,xx,yy,dp[(i+1)%2][xx][yy]);
                ans = max(ans,dp[(i+1)%2][xx][yy]);
            }
            ans+=grid[i][x];
            if(x!=y)  ans+=grid[i][y];
            dp[i%2][x][y]=ans;
            printf("dp[%d][%d][%d]=%d\n",i,x,y,ans);
            anss = max(ans,anss);
        }
        return anss;
    }
};
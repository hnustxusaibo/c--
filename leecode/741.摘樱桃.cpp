class Solution {
public:
    int n;
    bool cmp(int x){
        if(x<n && x>=0) {
            return false;
        }
        return true;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        n = grid.size();
        int dp[51][51][151] = {};
        for(int k=1;k<=2*(n-1)+1;k++){
            bool flag = 0;
            for(int i=0;i<n&&i<=k;i++)
            for(int x=0;x<n&&x<=k;x++){
                int j = k - i;
                int y = k - x;
                if(cmp(i)||cmp(j)||cmp(x)||cmp(y)||grid[i][j]==-1||grid[x][y]==-1) 
                    continue;
                // printf("dp[%d][%d][%d][%d]\n",i,j,x,y);
                flag = 1;
                int ans = 0;
                if(j>0&&y>0) ans = max(ans,dp[i][x][k-1]);
                if(i>0&&y>0) ans = max(ans,dp[i-1][x][k-1]);
                if(i>0&&x>0) ans = max(ans,dp[i-1][x-1][k-1]);
                if(j>0&&x>0) ans = max(ans,dp[i][x-1][k-1]);
                if(i==x) ans+=grid[i][j];
                else ans+=grid[i][j]+grid[x][y];
                dp[i][x][k] = ans;
                printf("dp[%d][%d][%d]=%d\n",i,x,k,ans);
                
            }
            if(flag == 0) return 0;
        }
        return dp[n-1][n-1][2*(n-1)];
    }
};
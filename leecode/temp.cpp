class Solution {
public:
    int maxScore(vector<vector<int>>& grid) {
        int ans = -1e9;
        for(int i=0;i<grid.size();i++)
        for(int j=0;j<grid[0].size();j++)
        {
            int mi = 0;
            if(i==0&&j==0) continue;
            if(i==0) mi=grid[i][j-1];
            if(j==0) mi=grid[i-1][j];
            if(i!=0&&j!=0) mi = min(grid[i-1][j],grid[i][j-1]);
            ans = max(ans, grid[i][j] - mi);
            grid[i][j] = min(grid[i][j], mi);
            printf("grid[%d][%d]=%d\n",i,j,grid[i][j]);
        }
        return ans;
    }
};
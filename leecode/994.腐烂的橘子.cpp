/*
 * @lc app=leetcode.cn id=994 lang=cpp
 *
 * [994] 腐烂的橘子
 *
 * https://leetcode.cn/problems/rotting-oranges/description/
 *
 * algorithms
 * Medium (51.30%)
 * Likes:    855
 * Dislikes: 0
 * Total Accepted:    172.2K
 * Total Submissions: 333.2K
 * Testcase Example:  '[[2,1,1],[1,1,0],[0,1,1]]'
 *
 * 在给定的 m x n 网格 grid 中，每个单元格可以有以下三个值之一：
 * 
 * 
 * 值 0 代表空单元格；
 * 值 1 代表新鲜橘子；
 * 值 2 代表腐烂的橘子。
 * 
 * 
 * 每分钟，腐烂的橘子 周围 4 个方向上相邻 的新鲜橘子都会腐烂。
 * 
 * 返回 直到单元格中没有新鲜橘子为止所必须经过的最小分钟数。如果不可能，返回 -1 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 
 * 
 * 输入：grid = [[2,1,1],[1,1,0],[0,1,1]]
 * 输出：4
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：grid = [[2,1,1],[0,1,1],[1,0,1]]
 * 输出：-1
 * 解释：左下角的橘子（第 2 行， 第 0 列）永远不会腐烂，因为腐烂只会发生在 4 个方向上。
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：grid = [[0,2]]
 * 输出：0
 * 解释：因为 0 分钟时已经没有新鲜橘子了，所以答案就是 0 。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * m == grid.length
 * n == grid[i].length
 * 1 <= m, n <= 10
 * grid[i][j] 仅为 0、1 或 2
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int des[4][2] = {{0,1},{0,-1},{-1,0},{1,0}};
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        queue<int> que;

        for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        if(grid[i][j]==2){
            que.push(i);
            que.push(j);
            que.push(0);
        }

        int ans = 0;
        while(!que.empty()){
            int i=que.front();que.pop();
            int j=que.front();que.pop();
            int time=que.front();que.pop();
            // printf("i=%d,j=%d,time=%d\n",i,j,time);
            ans=max(ans,time);

            for(int k=0;k<4;k++){
                int x = i + des[k][0];
                int y = j + des[k][1];
                if(x<0||x>=n||y<0||y>=m) continue;
                if(grid[x][y] == 1){
                    que.push(x);
                    que.push(y);
                    que.push(time+1);
                    grid[x][y] = 2;
                    // printf("x=%d,y=%d\n",x,y);
                }
            }
        }
        for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        if(grid[i][j]==1)
            return -1;
        
        return ans;
    }
};
// @lc code=end


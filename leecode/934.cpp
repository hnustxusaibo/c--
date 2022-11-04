#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
const int mod = 1e9 + 7;
const int MAX = 2e9 + 7;
const int N = 2e4 + 5;

int direction[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

int mmap[100][100];
queue<int> q;

void dfs(int x, int y, vector<vector<int>> &grid)
{
    mmap[x][y] = 1;
    q.push(x);
    q.push(y);
    int n = grid.size();
    for (int i = 0; i < 4; i++)
    {
        int xx = x + direction[i][0];
        int yy = y + direction[i][1];
        if (xx < 0 || yy < 0 || xx >= n || yy >= n)
            continue;
        if (mmap[xx][yy] == 0 && grid[xx][yy] == 1)
            dfs(xx, yy, grid);
    }
}

int shortestBridge(vector<vector<int>> &grid)
{
    int n = grid.size();
    bool f = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j] && f == 0)
            {
                dfs(i, j, grid);
                f = 1;
                break;
            }
        }
    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        int y = q.front();
        q.pop();
        printf("x=%d,y=%d,map[x][y]=%d\n", x, y, mmap[x][y]);
        for (int i = 0; i < 4; i++)
        {
            int xx = x + direction[i][0];
            int yy = y + direction[i][1];
            if (xx < 0 || yy < 0 || xx >= n || yy >= n)
                continue;
            if (mmap[xx][yy] == 0)
            {
                if (grid[xx][yy] == 0)
                    q.push(xx), q.push(yy), mmap[xx][yy] = mmap[x][y] + 1;
                else
                    return mmap[x][y] + 1;
            }
        }
    }
    return 0;
}
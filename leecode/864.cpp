#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
const int mod = 1e9 + 7;
const int MAX = 2e9 + 7;
const int N = 2e4 + 5;

bool dp[33][33][1 << 6];
int mp[33][33];

int X[4] = {0, 1, 0, -1};
int Y[4] = {1, 0, -1, 0};

int shortestPathAllKeys(vector<string> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    int t = 0;
    queue<int> qu;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == '.')
                mp[i][j] = 0;
            if (grid[i][j] == '#')
                mp[i][j] = -1;
            if (grid[i][j] == '@')
                mp[i][j] = 0, qu.push(i), qu.push(j), qu.push(0), qu.push(0);
            if ('A' <= grid[i][j] && grid[i][j] <= 'F')
                mp[i][j] = grid[i][j] - 'A' + 10 + 1;
            if ('a' <= grid[i][j] && grid[i][j] <= 'f')
                mp[i][j] = grid[i][j] - 'a' + 1, t++;
        }
    }
    while (!qu.empty())
    {
        int x, y, status, val;
        x = qu.front();
        qu.pop();
        y = qu.front();
        qu.pop();
        status = qu.front();
        qu.pop();
        val = qu.front();
        qu.pop();
        dp[x][y][status] = 1;
        printf("x=%d,y=%d,status=%o,val=%d\n", x, y, status, val);
        for (int i = 0; i < 4; i++)
        {
            int xx = x + X[i];
            int yy = y + Y[i];
            if (xx < 0 || x >= n || yy < 0 || yy >= m)
                continue;
            if (mp[xx][yy] == -1 || dp[xx][yy][status] == 1)
                continue;
            if (mp[xx][yy] > 10 && (status & (1 << (mp[xx][yy] - 11))) == 0)
                continue;
            printf("%d\b",(status & (1 << (mp[xx][yy] - 11)));
            dp[xx][yy][status] = 1;
            if (mp[xx][yy] > 0 && mp[xx][yy] < 7 && (status&(1<<mp[xx][yy]-1))==0)
            {
                printf("xx=%d,yy=%d,mp=%d\n", xx, yy, mp[xx][yy]);
                status += (1 << mp[xx][yy] - 1);
                if (status == (1 << t) - 1)
                    return val + 1;
            }
            qu.push(xx);
            qu.push(yy);
            qu.push(status);
            qu.push(val + 1);
            dp[xx][yy][status] = 1;
        }
    }
    return -1;
}
int n = grid.size();
int m = grid[0].size();
queue<int> qu;
for (int i = 0; i < n; i++)
{
    for (int j = 0; j < m; j++)
    {
        if (grid[i][j] == '.')
            mp[i][j] = 0;
        if (grid[i][j] == '#')
            mp[i][j] = -1;
        if (grid[i][j] == '@')
            mp[i][j] = 0, qu.push(i), qu.push(j), qu.push(0), qu.push(0);
        if ('A' <= grid[i][j] && grid[i][j] <= 'F')
            mp[i][j] = grid[i][j] - 'A' + 10 + 1;
        if ('a' <= grid[i][j] && grid[i][j] <= 'f')
            mp[i][j] = grid[i][j] - 'a' + 1;
    }
}
while (!qu.empty())
{
    int x, y, status, val;
    x = qu.front();
    qu.pop();
    y = qu.front();
    qu.pop();
    status = qu.front();
    qu.pop();
    val = qu.front();
    qu.pop();
    printf("x=%d,y=%d,status=%o,val=%d\n", x, y, val, status);
    for (int i = 0; i < 4; i++)
    {
        int xx = x + X[i];
        int yy = y + Y[i];
        if (xx < 0 || x >= n || yy < 0 || yy >= m)
            continue;
        if (mp[xx][yy] != -1 || dp[xx][yy][status] == 1)
            continue;
        if (mp[xx][yy] > 10 && (status & (1 << (mp[xx][yy] - 10) == 0)))
            continue;
        dp[xx][yy][status] == 1;
        if (mp[xx][yy] > 0 && mp[xx][yy] < 7)
        {
            status &= (1 << mp[xx][yy]);
            if ((status & 0b111111) == 0b111111)
                return val + 1;
        }
        qu.push(xx);
        qu.push(yy);
        qu.push(status);
        qu.push(val + 1);
        dp[xx][yy][status] == 1;
    }
}
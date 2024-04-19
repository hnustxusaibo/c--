#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
const int mod = 1e9 + 7;
const int MAX = 2e9 + 7;
const int N = 1e5 + 5;

int ans[102][102];
int minFallingPathSum(vector<vector<int>> &grid) {
    int n = grid.size();
    int m = grid[0].size();
    int anss = 1e9;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            if (i == 0)
                ans[i][j] = grid[i][j];
            else {
                int mi = 1e9;
                for (int k = 0; k < m; k++)
                    if (k != j) mi = min(mi, ans[i - 1][k]);
                ans[i][j] = mi + grid[i][j];
            }
            if (i == n - 1) {
                anss = min(anss, ans[i][j]);
            }
        }
    return anss;
}
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;
const int mod = 1e9+7;
const int MAX = 2e9+7;
const int N = 1e3+5;

int mp[55][55];

int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    for(int i=0;i<n;i++)
    for(int j=0;j<m;j++) mp[i][j]=MAX;

    for(int i=0;i<n;i++){
        int ma = 0;
        for(int j=0;j<m;j++){
            ma = max(ma,grid[i][j]);
        }
        for(int j=0;j<m;j++) mp[i][j]=min(ma,mp[i][j]);
    }
    for(int j=0;j<m;j++){
        int ma = 0;
        for(int i=0;i<n;i++){
            ma = max(ma,grid[i][j]);
        }
        for(int i=0;i<n;i++) mp[i][j]=min(ma,mp[i][j]);
    }

    int ans = 0;
    for(int i=0;i<n;i++)
    for(int j=0;j<m;j++) ans+=mp[i][j]-grid[i][j];
    return ans;
}


#include <bits/stdc++.h>

using namespace std;


typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;
const int mod = 1e9+7;
const int MAX = 2e9+7;
const int N = 200+5;


typedef pair<int,pii> piii;
priority_queue<piii> q;

bool mp[N][N][2];

vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
    int n = heights.size();
    for(int i=0;i<n;i++){
        mp[0][i][0] = 1;
        mp[i][0][0] = 1;

        mp[n-1][i][1] = 1;
        mp[i][n-1][1] = 1;
    }

    for(int i=1;i<n-1;i++){
        for(int j=1;j<n-1;j++){
            piii x;
            x.first = -heights[i][j];
            x.second.first = i;
            x.second.second = j;
            q.push(x);
        }
    }

    while(!q.empty()){
        piii x = q.top();
        q.pop()
    }
}
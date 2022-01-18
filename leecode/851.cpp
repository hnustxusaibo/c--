#include <bits/stdc++.h>

using namespace std;


typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;
const int mod = 1e9+7;
const int MAX = 2e9+7;
const int N = 1e3+5;

vector<int> ans;
vector<int> mp[505];

int solve(int t,vector<int>& quiet){
    if(ans[t]!=-1) return ans[t];
    int mi = 1e9;
    for(int x : mp[t]){
        mi = min(mi,solve(x,quiet));
    }
    ans[t] = mi;
    return mi;
}

vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
    for(int i=0;i<quiet.size();i++) ans.push_back(-1);
    for(auto x : richer){
        mp[x[0]].push_back(x[1]);
    }
    for(int i=0;i<quiet.size();i++){
        ans[i] = solve(i,quiet);
    }
    return ans;
}
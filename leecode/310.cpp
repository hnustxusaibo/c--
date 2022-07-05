#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
const int mod = 1e9 + 7;
const int N = 1e4 + 5;

vector<int> mp[N];
int ans = 1e9;
vector<int> anss;

int dfs(int node, int deep, int father)
{
    if (mp[node].size() == 1 && father != -1)
    {
        return 1;
    }
    vector<int> deeps;
    deeps.push_back(deep);
    int ma = 0;
    for (int i = 0; i < mp[node].size(); i++)
        if (mp[node][i] != father)
        {
            int len = dfs(mp[node][i], deep + 1, node);
            ma = max(ma, len);
            deeps.push_back(len);
        }
    sort(deeps.begin(), deeps.end(), greater<int>());
    int def = (deeps[0] + deeps[1] + 1) / 2;
    if(def < ans){
        printf("node=%d\n",node);
        anss.clear();
        anss.push_back(node);
    }
    if(def == ans){
        anss.push_back(node);
    }
    return ma + 1;
}

vector<int> findMinHeightTrees(int n, vector<vector<int>> &edges)
{
    for (auto edge : edges)
    {
        mp[edge[0]].push_back(edge[1]);
        mp[edge[1]].push_back(edge[0]);
    }
    dfs(0, 0, -1);
    return anss;
}
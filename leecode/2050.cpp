#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
const int mod = 1e9 + 7;
const int MAX = 2e9 + 7;
const int N = 2e4 + 5;

#define PRINT_VAR(x) std::cout << #x << "=" << x << std::endl

int du[50005], ans[50005];
queue<int> dus;
int minimumTime(int n, vector<vector<int>> &relations, vector<int> &time)
{
    vector<vector<int>> mp(n);
    for (auto relation : relations)
    {
        mp[relation[0] - 1].push_back(relation[1] - 1);
        du[relation[1] - 1]++;
    }
    for (int i = 0; i < n; i++)
        if (du[i] == 0)
            dus.push(i);
    int anss = 0;
    while (!dus.empty())
    {
        int t = dus.front();
        dus.pop();
        ans[t] += time[t];
        anss = max(anss, ans[t]);
        // PRINT_VAR(t);
        // PRINT_VAR(ans[t]);
        for (auto tt : mp[t])
        {
            // PRINT_VAR(tt);
            du[tt]--;
            ans[tt] = max(ans[tt], ans[t]);
            if (du[tt] == 0)
                dus.push(tt);
        }
    }
    return anss;
}
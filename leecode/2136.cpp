#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
const int mod = 1e9 + 7;
const int MAX = 2e9 + 7;
const int N = 2e4 + 5;

#define PRINT_VAR(x) std::cout << #x << "=" << x << std::endl
typedef pair<int, int> pii;
int earliestFullBloom(vector<int> &plantTime, vector<int> &growTime)
{
    int n = plantTime.size();
    vector<pii> p(n);
    int time = 0;
    for (int i = 0; i < n; i++)
        p.push_back(pii(growTime[i], plantTime[i])), time += plantTime[i];
    std::sort(p.begin(), p.end());
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans = max(ans, time + p[i].first);
        time -= p[i].second;
    }
    return ans;
}
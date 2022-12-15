#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
const int mod = 1e9 + 7;
const int MAX = 2e9 + 7;
const int N = 1e5 + 5;

vector<int> minOperations(string boxes)
{
    int n = boxes.size();
    vector<int> ans;
    int l = 0;
    int t = 0;
    for (int i = 0; i < n; i++)
    {
        t += l;
        if (boxes[i] == '1')
            l++;
        ans[i] += t;
    }

    for (int i = n - 1; i >= 0; i--)
    {
        t += l;
        if (boxes[i] == '1')
            l++;
        ans[i] += t;
    }
    return ans;
}
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
const int mod = 1e9 + 7;
const int MAX = 2e9 + 7;
const int N = 1e3 + 5;

typedef pair<char, int> pri;
vector<pri> transform(string &s)
{
    vector<pri> ans;
    for (int i = 0; i < s.size(); i++)
    {
        int t = 0;
        while (i + t < s.size() && s[i + t] == s[i])
            t++;
        ans.push_back(pri(s[i], t));
        i += t;
    }
    return ans;
}

bool diff(vector<pri> &s, vector<pri> &w)
{
    if (s.size() != w.size())
        return false;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i].first != w[i].first)
            return false;
        if (s[i].second < w[i].second)
            return false;
        if (s[i].second > w[i].second && s[i].second - w[i].second < 2)
            return false;
    }
    return true;
}

int expressiveWords(string s, vector<string> &words)
{
    vector<pri> _s = transform(s);
    int ans = 0;
    for (auto w : words)
    {
        auto _w = transform(w);
        if (diff(_s, _w))
            ans++;
    }
    return ans;
}

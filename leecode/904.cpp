#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
const int mod = 1e9 + 7;
const int MAX = 2e9 + 7;
const int N = 2e4 + 5;

map<int, int> mp;
int totalFruit(vector<int> &fruits)
{
    int l, ans;
    l = 0;
    ans = 0;
    int n = fruits.size();
    for (int i = 0; i < n; i++)
    {
        mp[fruits[i]]++;
        if (mp.size() > 2)
        {
            while (mp.size() > 2)
            {
                mp[fruits[l]]--;
                if (mp[fruits[l]] == 0)
                    mp.erase(fruits[l]);
                l++;
            }
        }
        ans = max(ans, i - l + 1);
    }
    ans = max(ans, n - l);
    return ans;
}

int main(int argc, char const *argv[])
{
    vector<int> vec = {1, 2, 3, 2, 2};
    cout << totalFruit(vec) << endl;
    return 0;
}

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
const int mod = 1e9 + 7;
const int MAX = 2e9 + 7;
const int N = 2e4 + 5;

int atMostNGivenDigitSet(vector<string> &digits, int n)
{
    printf("n=%d\n", n);
    if (n == 0)
        return 0;
    int t, x, tt;
    x = n, t = 1, tt = 0;
    while (x >= 10)
        x /= 10, t *= 10, tt++;
    int xx = 0;
    int ans = 0;
    int zz = 1;
    if (tt == 0)
        zz = 0;
    for (auto s : digits)
    {
        int v = s[0] - '0';
        if (v < x)
            zz++;
        if (v == x)
            ans += atMostNGivenDigitSet(digits, n - x * t);
    }
    ans += zz * pow(digits.size() - 1, tt);
    return ans;
}

int main(int argc, char const *argv[])
{
    vector<string> vec = {"1", "3", "5", "7"};
    cout << atMostNGivenDigitSet(vec, 100) << endl;
    return 0;
}
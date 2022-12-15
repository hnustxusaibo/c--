#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
const int mod = 1e9 + 7;
const int MAX = 2e9 + 7;
const int N = 1e5 + 5;

int gcd(int a, int b)
{
    return b == 0 ? a : gcd(b, a % b);
}

int nthMagicalNumber(int n, int a, int b)
{
    int l = a * b / gcd(a, b);
    int t = l / a + l / b - 1;
    int nn = n / t;
    int nnn = n % t;

    int ans = (1ll * l * t) % mod;
    int aa = 0;
    int bb = 0;
    while (nnn--)
    {
        if (aa + a < bb + b)
        {
            aa += a;
        }
        else
        {
            bb += b;
        }
    }
    return (ans + min(aa, bb)) % mod;
}
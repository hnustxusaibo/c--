#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int quickPower(int x, int y, int mod)
{
    int ans = 1;
    while (y)
    {
        if (y & 1)
            ans = (1ll * ans * x) % mod;
        y >>= 1;
        x = (1ll * x * x) % mod;
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    cout << quickPower(2, 100, 10000) << endl;
    return 0;
}

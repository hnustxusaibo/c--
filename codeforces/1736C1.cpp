#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
const int mod = 1e9 + 7;
const int N = 2e5 + 5;

int a[N];
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int l = 0;
        long long ans = 0;
        for (int i = 1; i <= n; i++)
        {
            int x;
            cin >> x;
            if (x >= i)
                l++;
            else
            {
                ans++;
                if (l > 0)
                    ans += l * (l + 1) / 2, l = 0;
            }
        }
        if (l > 0)
            ans += l * (l + 1) / 2;
        cout << ans << endl;
    }
    return 0;
}
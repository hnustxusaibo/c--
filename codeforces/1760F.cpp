#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
const int mod = 1e9 + 7;
const int N = 2e5 + 5;

ll a[N];
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll n, c, d;
        cin >> n >> c >> d;
        for (int i = 0; i < n; i++)
            cin >> a[i];
        sort(a, a + n, greater<int>());
        if (a[0] * d < c)
        {
            printf("Impossible\n");
            continue;
        }
        ll sum = 0;
        for (int i = 0; i < min(n, d); i++)
            sum += a[i];
        if (sum >= c)
        {
            printf("Infinity\n");
            continue;
        }
    }
    return 0;
}
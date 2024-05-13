#include <bits/stdc++.h>

#include <hash_set>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
const int mod = 1e9 + 7;
const int N = 1e3 + 5;

int main() {
    int q;
    cin >> q;
    unordered_set<ll> se;
    se.clear();
    while (q--) {
        char c;
        long long x;
        cin >> c >> x;
        if (c == '+') {
            se.insert(x);
        }
        if (c == '?') {
            for (int i = 1; i <= se.size() + 1; i++)
                if (se.count(i * x) == 0) {
                    cout << i * x << endl;
                    break;
                }
        }
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int sum[100];
typedef pair<int, int> pii;
vector<pii> vec;

int main() {
    string s;
    cin >> s;
    for (int i = 0; i < s.size(); i++) {
        int c = s[i] - 'a';
        if (c >= 0 && c < 26) sum[c]++;
    }
    for (int i = 0; i < 26; i++) {
        vec.push_back(pii(sum[i], -i));
    }
    sort(vec.begin(), vec.end());
    if (vec[25].first == vec[24].first)
        cout << "ERROR" << endl;
    else {
        printf("%c-%d", 'a' - vec[24].second, vec[24].first);
    }
}
// 64 位输出请用 printf("%lld")
#include <chrono>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <thread>
#include <vector>

using namespace std;

int main() {
    int q;
    cin >> q;
    while (q--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n, 0);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        while (k--) {
            int x, y;
            cin >> x >> y;
            a[x]++;
            a[y]--;
        }
        bool flag = true;
        for (int i = 1; i < n; i++) {
            if (a[i] > a[i - 1]) {
                flag = false;
                break;
            }
        }
        cout << (flag ? "Yes" : "No") << endl;
    }

    return 0;
}
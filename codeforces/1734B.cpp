#include <bits/stdc++.h>

using namespace std;


typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;
const int mod = 1e9+7;
const int N = 1e3+5;


int main()
{
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        for(int k=1;k<=n;k++){
            if (k == 1) {cout << "1" << endl; continue;}
            if (k == 2) {cout << "1 1" << endl; continue;}
            cout << "1 ";
            for (int i = 0; i < k - 2; i++) cout << "0 ";
            cout << "1" << endl;
        }
    }
    return 0;
}
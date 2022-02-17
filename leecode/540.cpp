#include <bits/stdc++.h>

using namespace std;


typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;
const int mod = 1e9+7;
const int MAX = 2e9+7;
const int N = 2e4+5;

int singleNonDuplicate(vector<int>& nums) {
    int a = 0;
    for(auto x : nums) a^=x;
    return a;
}
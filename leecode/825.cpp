#include <bits/stdc++.h>

using namespace std;


typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;
const int mod = 1e9+7;
const int MAX = 2e9+7;
const int N = 1e3+5;

vector<int> ans;
vector<int> mp[505];

int numFriendRequests(vector<int>& ages) {
    int n = ages.size();
    sort(ages.begin(),ages.end());
    int ans = 0;
    for(int x=0;x<n;x++) {
        for(int y=0;y<x;y++)
            if(!((ages[y] <= 0.5 * ages[x] + 7)||(ages[y] > ages[x])||(ages[y] > 100 && ages[x] < 100)))
                ans++;
    }
    return ans;
}
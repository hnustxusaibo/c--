#include <bits/stdc++.h>

using namespace std;


typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;
const int mod = 1e9+7;
const int MAX = 2e9+7;
const int N = 2e4+5;

int mp[30][30];

int maximumRequests(int n, vector<vector<int>>& requests) {
    int m = 0;
    for(auto request : requests){
        if(request[0]==request[1]){
            m++;
            continue;
        }
        mp[request[0]][request[1]]++;
    }
    int ans = 0;
    for(int i=0;i<n;i++) ans = max(ans,solve(i));
    return ans + m ;
}
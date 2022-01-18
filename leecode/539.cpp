#include <bits/stdc++.h>

using namespace std;


typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;
const int mod = 1e9+7;
const int MAX = 2e9+7;
const int N = 2e4+5;

int findMinDifference(vector<string>& timePoints) {
    vector<int> times;
    for(string time : timePoints){
        int h = (time[0]-'0')*10+(time[1]-'0');
        int m = (time[0]-'0')*10+(time[1]-'0');
        times.push_back(h*60+m);
    }
    sort(times.begin(),times.end());
    times.push_back(times[0] + 24*60);
    int ans = 1e9;
    for(int i=1;i<times.size();i++) ans=min(ans,times[i]-times[i-1]);
    return ans;
}
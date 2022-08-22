#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
const int mod = 1e9 + 7;
const int MAX = 2e9 + 7;
const int N = 1e5 + 5;

int dp[N];
map<int, int> mp;

int maxEqualFreq(vector<int>& nums) {
  int ans = 0;
  for(int i=0;i<nums.size();i++) {
    int x = nums[i];
    if (dp[x]) {
      mp[dp[x]]--;
      if (mp[dp[x]] == 0) mp.erase(dp[x]);
    }
    dp[x]++;
    mp[dp[x]]++;
    if(mp.size() == 2){
        for(auto it : mp){
            printf("i=%d,key=%d,val=%d\n",i,it.first,it.second);
            if(it.second == 1){
                ans = i+1;
                break;
            }
        }
    }
  }
  return ans;
}
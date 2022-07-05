#include <bits/stdc++.h>

using namespace std;


typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;
const int mod = 1e9+7;
const int MAX = 2e9+7;
const int N = 2e4+5;

stack<int> s;

long long subArrayRanges(vector<int>& nums) {
    ll ans = 0;
    for(int i=0;i<nums.size();i++){
        while(!s.empty()&& nums[i] < nums[s.top()]){
            int mid = s.top();
            s.pop();
            int l = s.empty()?0:s.top()+1;
            int r = i-1;
            ans -= 1ll*(mid-l+1)*(r-mid+1)*nums[mid];
            printf("less num=%d,l=%d,r=%d\n",nums[mid],l,r);
        }
        s.push(i);
    }
    while(!s.empty()){
        int mid = s.top();
        s.pop();
        int l = s.empty()?0:s.top()+1;
        int r = nums.size() - 1;
        ans -= 1ll*(mid-l+1)*(r-mid+1)*nums[mid];
        printf("less num=%d,l=%d,r=%d\n",nums[mid],l,r);
    }

    for(int i=0;i<nums.size();i++){
        while(!s.empty()&& nums[i] > nums[s.top()]){
            int mid = s.top();
            s.pop();
            int l = s.empty()?0:s.top()+1;
            int r = i-1;
            ans += 1ll*(mid-l+1)*(r-mid+1)*nums[mid];
            printf("greater num=%d,l=%d,r=%d\n",nums[mid],l,r);
        }
        s.push(i);
    }
    while(!s.empty()){
        int mid = s.top();
        s.pop();
        int l = s.empty()?0:s.top()+1;
        int r = nums.size() - 1;
        ans += 1ll*(mid-l+1)*(r-mid+1)*nums[mid];
        printf("greater num=%d,l=%d,r=%d\n",nums[mid],l,r);
    }
    return ans;

}
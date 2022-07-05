#include <bits/stdc++.h>

using namespace std;


typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;
const int mod = 1e9+7;
const int MAX = 2e9+7;
const int N = 2e4+5;

int sum[100005];

void add(int x,int y){
    sum[x]++;
    sum[y+1]--;
}

void sub(int x,int y){
    sum[x]--;
    sum[y+1]++;
}

int bestRotation(vector<int>& nums) {
    int n = nums.size();
    for(int i=0;i<n;i++){
        int x = nums[i];
        if(x-i<0){
            add(i-x,i);
        }else {
            if(x-n<0){
                sub(i+1,i+(n-x));
                add(0,n);
            }
            else {
                add(0,n);
            }
        }
    }
    int ans = 0,anss=0;
    int s = 0;
    for(int i=0;i<n;i++){
        s += sum[i];
        if(ans<s){
            ans = s;
            anss = i;
        }
        ans = max(ans,s);
    }
    return anss;
}
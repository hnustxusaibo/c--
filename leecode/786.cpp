#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;
const int mod = 1e9+7;
const int N = 1e3+5;

vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {    
    double l = 0.0, r=1.0;
    vector<int> ans={0,0};
    while(true){
        double m = (l+r)/2;
        ans[0]=0;
        ans[1]=1;
        int cnt = 0;
        for(int j=1;j<arr.size();j++){
            for(int i=0;i<j&&arr[i]<=arr[j]*m;i++){
                if(arr[i]*ans[1] > ans[0]*arr[j]){
                    ans[0] = arr[i];
                    ans[1] = arr[j];
                }
                cnt++;
            }
        }
        printf("cnt=%d m=%f\n",cnt,m);
        if(cnt==k) break;
        if(cnt<k) l=m;
        if(cnt>k) r=m;
    }
    return ans;
}

int main()
{
   
   return 0;
}
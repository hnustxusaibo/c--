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
       ll n,h,a[101],cha[101];
       cin >> n >> h;
       for(int i=0;i<n;i++) cin >> a[i];
       cha[0]=0;
       for(int i=0;i<n-1;i++) cha[i+1] = a[i+1]-a[i];
       sort(cha+1,cha+n);
       ll ans = 0;
       int i=1;
       while(i<n){
            ll num = (cha[i]-cha[i-1]) * (n-i+1);
            if(ans + num >= h) break; 
            ans += num;
            i++;
       }
       ll down = n-i+1;
       ll up = h - ans;
       printf("%lld\n",cha[i-1] + (up+down-1)/down);
   }
   return 0;
}
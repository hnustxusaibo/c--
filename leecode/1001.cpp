#include <bits/stdc++.h>

using namespace std;


typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;
const int mod = 1e9+7;
const int MAX = 2e9+7;
const int N = 2e4+5;
vector<int> Xlist={-1,0,1};


map<int,int> aa,bb,cc,dd;
set<ll> mp;

void insert(ll x, ll y){
    ll cmp = x*1e9 + y;
    mp.insert(cmp);
}

bool find(ll x, ll y){
    ll cmp = x*1e9 + y;
    return mp.count(cmp);
}

void erase(ll x, ll y){
    ll cmp = x*1e9 + y;
    mp.erase(cmp);
}

vector<int> gridIllumination(int n, vector<vector<int>>& lamps, vector<vector<int>>& queries) {
    for(auto t: lamps){
        int x = t[0];
        int y = t[1];
        if(find(x,y)) continue;
        insert(x,y);
        aa[x]++;
        bb[y]++;
        cc[x-y]++;
        dd[x+y]++;
    }
    vector<int> ans;
    for(auto q: queries){
        int x = q[0];
        int y = q[1];
        printf("aa[x]=%d,bb[y]=%d,cc[x-y]=%d,dd[x+y]=%d\n",aa[x],bb[y],cc[x-y],dd[x+y]);
        if(aa[x]==0&&bb[y]==0&&cc[x-y]==0&&dd[x+y]==0) ans.push_back(0);
        else ans.push_back(1);
        for(int i=0;i<3;i++)
        for(int j=0;j<3;j++){
            int xx = x + Xlist[i];
            int yy = y + Xlist[j];
            if(xx>=0&&yy>=0&&find(xx,yy)){
                printf("xx=%d,yy=%d\n",xx,yy);
                erase(xx,yy);
                aa[xx]++;
                bb[yy]++;
                cc[xx-yy]++;
                dd[xx+yy]++;
            }
        }
    }
    return ans;
}
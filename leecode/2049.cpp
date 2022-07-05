#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;
const int mod = 1e9+7;
const int MAX = 2e9+7;
const int N = 1e5+5;

vector<int> mp[100005];
int score[100005];
int dfs(int cnt){
    int sum = 1;
    for(int i=0;i<mp[cnt].size();i++){
        sum+=dfs(mp[cnt][i]);
    }
    score[cnt]=sum;
    //printf("cnt=%d,score[cnt]=%d\n",cnt,score[cnt]);
    return sum;
}

int countHighestScoreNodes(vector<int>& parents) {
    int n = parents.size();
    for(int i=0;i<n;i++){
        if(parents[i]!=-1){
            mp[parents[i]].push_back(i);
        }
    }
    dfs(0);
    ll ans = 0;
    ll anss[100005];
    for(int i=0;i<n;i++){
        ll s = 1;
        int sun = 0;
        for(auto t: mp[i]){
            if(score[t]) s*=score[t];
            sun+=score[t];
            //printf("i=%d,score[t]=%d\n",i,score[t]);
        }
        if(n-sun-1!=0) s*=(n-sun-1);
       // printf("i=%d,sun=%d,s=%d\n",i,sun,s);
        ans = max(ans,s);
        anss[i]=s;
    }
    int ss = 0;
    for(int i=0;i<n;i++) if(anss[i]==ans) ss++;
    return ss;
}
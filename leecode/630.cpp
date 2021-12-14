#include <bits/stdc++.h>

using namespace std;


typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;
const int mod = 1e9+7;
const int MAX = 2e9+7;
const int N = 1e3+5;

priority_queue<int,vector<int>,less<int> > pq;

int scheduleCourse(vector<vector<int>>& courses) {
    vector<pii> ve;
    for(auto x : courses){
        pii cnt;
        cnt.first = x[1];
        cnt.second = x[0];
        ve.push_back(cnt);
    }
    sort(ve.begin(),ve.end());
    int time = 0;
    for(pii x : ve){
        if(x.second>x.first) continue;
        if(pq.empty()){
            pq.push(x.second);
            time+=x.second;
        }else{
            int top = pq.top();
            if(time + x.second <= x.first){
                pq.push(x.second);
                time+=x.second;
            }else if(top>x.second && time + x.second - top <= x.first){
                pq.pop();
                pq.push(x.second);
                time += x.second - top;
            }
        }
        printf("x = %d , y = %d, time = %d\n",x.first,x.second,time);
    }
    return pq.size();
}
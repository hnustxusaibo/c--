#include <bits/stdc++.h>

using namespace std;


typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;
const int mod = 1e9+7;
const int MAX = 2e9+7;
const int N = 2e4+5;

double mp[26][26][101];
bool f[26][26][101];
int X[8] = {-2,-2,-1,-1,1,1,2,2};
int Y[8] = {-1,1,-2,2,-2,2,-1,1}; 

double knightProbability(int n, int k, int row, int column) {
    if(row >= n || column >= n || row < 0 || column < 0 ) return 0.0;
    if(k==0) return 1.0;
    if(f[row][column][k]) return mp[row][column][k];
    double ans = 0.0;

    for(int i=0;i<8;i++){
        int x = row + X[i];
        int y = column + Y[i];
        ans += knightProbability(n,k-1,x,y) * 0.125;
    }

    mp[row][column][k] = ans;
    f[row][column][k] = 1;
    return ans;
}
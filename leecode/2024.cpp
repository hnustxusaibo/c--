#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;
const int mod = 1e9+7;
const int MAX = 2e9+7;
const int N = 1e5+5;

int maxConsecutiveChar(string& answerKey, int k, char ch) {
    int ans = 0;
    int n = answerKey.size();
    for(int l = 0, r = 0, v = 0;r < n ,r++){
        if(answerKey[r] == ch){
            
        }else {
            
        }
    }
}

int maxConsecutiveAnswers(string answerKey, int k) {
    return max(maxConsecutiveChar(answerKey,k,'T'),
               maxConsecutiveChar(answerKey,k,'F'));
}
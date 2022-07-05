#include <bits/stdc++.h>

using namespace std;


typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;
const int mod = 1e9+7;
const int MAX = 2e9+7;
const int N = 2e4+5;

bool oneEditAway(string first, string second) {
    int len1 = first.size();
    int len2 = second.size();
    if(len1==len2){
        int l = 0;
        for(int i=0;i<len2;i++) if(first[i]!=second[i]) l++;
        return l<=1;
    }
    if(len1==len2-1){
        swap(len1,len2);
        swap(first,second);
    }
    if(len1-1==len2){
        int l = 0;
        while(l<len1&&second[l]==first[l]){
            l++;
        }
        if(l==len1) return true;
        int ll = l+1;
        while(l<len1&&second[l]==first[ll]){
            l++;
            ll++;
        }
        if(l==len1) return true;
    }
    return false;
}

int main()
{
    oneEditAway("islander","slander");
    return 0;
}

#include <bits/stdc++.h>

using namespace std;


typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;
const int mod = 1e9+7;
const int MAX = 2e9+7;
const int N = 2e4+5;

class SORTracker {
public:
    struct tarcker
    {
        string name;
        int score;
        tarcker(string x,int y):name(x),score(y){}
    };
    
    
    struct cmp
    {
        bool operator()(tarcker a,tarcker b)
        {
            if(a.score == b.score)  return a.name >= b.name;
            else return a.score > b.score;
        }
    };

    

    SORTracker() {

    }
    
    void add(string name, int score) {

    }
    
    string get() {

    }
};
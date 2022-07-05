#include <bits/stdc++.h>

using namespace std;


typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;
const int mod = 1e9+7;
const int MAX = 2e9+7;
const int N = 2e4+5;

int jisuan(int a,char sign,int b){
    if(sign == '+') return a+b;
    if(sign == '-') return a-b;
    if(sign == '*') return a*b;
    return 0;
}

vector<int> diffWaysToCompute(string expression) {
    int n = expression.size();
    int l = 0;
    vector<int> nums;
    vector<char> signs;
    for(int i=0;i<n;i++) if(expression[i]=='*'||expression[i]=='-'||expression[i]=='+') {
        signs.push_back(expression[i]);
        nums.push_back(stoi(expression.substr(l,i-l+1)));
        l = i+1;
    }
    nums.push_back(stoi(expression.substr(l,n-l+1)));
    for(auto c : nums) cout << c << endl;
    for(auto c : signs) cout << c << endl;
    set<int> ans[20][20];
    for(int i=0;i<nums.size();i++){
        ans[i][i].insert(nums[i]);
    }
    for(int l=1;l<nums.size();l++){
        for(int i=0;i+l<nums.size();i++){
            int j = i+l;
            for(int k=i;k<j;k++){
                int sign = signs[k];
                set<int> left = ans[i][k];
                set<int> right = ans[k+1][j];
                for(auto le : left)
                for(auto ri : right)
                    ans[i][j].insert(jisuan(le,sign,ri));
            }
        }
    }
    vector<int> v(ans[0][nums.size()-1].begin(),ans[0][nums.size()-1].end());
    return v;
}

int main()
{
    diffWaysToCompute("2-1-1");
    return 0;
}

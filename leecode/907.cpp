#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
const int mod = 1e9 + 7;
const int MAX = 2e9 + 7;
const int N = 2e4 + 5;

int sumSubarrayMins(vector<int> &arr)
{
    stack<int> st;
    long long ans = 0;
    while (!st.empty())
        st.pop();
    for (int i = 0; i < arr.size(); i++)
    {
        while (!st.empty() && arr[i] < arr[st.top()])
        {
            int val = st.top();
            st.pop();
            int l = 0;
            if (!st.empty())
                l = st.top() + 1;
            int r = i - 1;
            printf("l=%d,r=%d,val=%d\n", l, r, arr[val]);
            ans = (ans + (val - l + 1) * (r - val + 1)) % mod;
        }
        st.push(i);
    }
    while (!st.empty())
    {
        int val = st.top();
        st.pop();
        int l = 0;
        if (!st.empty())
            l = st.top() + 1;
        int r = arr.size() - 1;
        printf("l=%d,r=%d,val=%d\n", l, r, arr[val]);
        ans = (ans + (val - l + 1) * (r - val + 1)) % mod;
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    vector<int> vec = {1, 3, 5, 7};
    cout << sumSubarrayMins(vec) << endl;
    return 0;
}
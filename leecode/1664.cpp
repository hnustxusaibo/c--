#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
const int mod = 1e9 + 7;
const int MAX = 2e9 + 7;
const int N = 2e4 + 5;

int waysToMakeFair(vector<int> &nums)
{
    int n = nums.size();
    int ji = 0;
    int ou = 0;
    for (int i = 0; i < n; i++)
    {
        if (i & 1)
            ji++;
        else
            ou++;
    }
    int jj = 0, oo = 0, ans = 0;
    for (int i = 0; i < n; i++)
    {
        printf("ji=%d,ou=%d,jj=%d,oo=%d\n", ji, ou, jj, oo);
        if (i & 1)
            ji -= nums[i];
        else
            ou -= nums[i];

        if (jj + ou == ji + oo)
            ans++;

        if (i & 1)
            jj += nums[i];
        else
            oo += nums[i];
    }
    return ans;
}
int main(int argc, char const *argv[])
{
    vector<int> vec = {1, 3, 5, 7};
    cout << waysToMakeFair(vec) << endl;
    return 0;
}
#include <bits/stdc++.h>

using namespace std;

const int N = 1e2 + 5;
int tree[N << 2];
int x;

void build(int l, int r, int cnt, vector<int> &arr)
{
    if (l == r)
    {
        tree[cnt] = arr[x++];
        return;
    }
    int m = (l + r) >> 1;
    build(l, m, cnt << 1, arr);
    build(m + 1, r, cnt << 1 | 1, arr);
    tree[cnt] = tree[cnt << 1] ^ tree[cnt << 1 | 1];
}

int query(int l, int r, int cnt, int L, int R)
{
    if (L <= l && r <= R)
    {
        return tree[cnt];
    }
    int m = (l + r) >> 1;
    int ans = 0;
    if (L <= m)
        ans ^= query(l, m, cnt << 1, L, R);
    if (R > m)
        ans ^= query(m + 1, r, cnt << 1 | 1, L, R);
    return ans;
}

vector<int> xorQueries(vector<int> &arr, vector<vector<int> > &queries)
{
    vector<int> ans;
    ans.clear();
    int n = arr.size();
    x = 0;
    build(1, n, 1, arr);
    for (int i = 0; i < queries.size(); i++)
    {
        vector<int> t = queries[i];
        ans.push_back(query(1, n, 1, t[0]+1, t[1]+1));
    }
    return ans;
}

int main()
{
    int v1[] = {1, 3, 4, 8};
    int v2[4][2] = {{2, 3}, {1, 3}, {0, 0}, {0, 3}};
    vector<vector<int> > queries;
    vector<int> arr;
    arr.clear();
    for (int i = 0; i < 4; i++)
    {
        arr.push_back(v1[i]);
    }

    for (int i = 0; i < 4; i++)
    {
        vector<int> x;
        x.clear();
        for (int j = 0; j < 2; j++)
        {
            x.push_back(v2[i][j]);
        }
        queries.push_back(x);
    }

    vector<int> ans = xorQueries(arr, queries);
    for (int i = 0; i < 4; i++)
        cout << ans[i] << endl;
    return 0;
}
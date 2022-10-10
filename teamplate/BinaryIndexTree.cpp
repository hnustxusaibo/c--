#include <bits/stdc++.h>

using namespace std;

#define N 50005
#define lowbit(x) ((x) & (-x))

int tree[N];
void update(int index, int x)
{
    for (int pos = index; pos < N; pos += lowbit(pos))
        tree[pos] += x;
}

int query(int index)
{
    int ans = 0;
    for (int pos = index; pos != 0; pos -= lowbit(pos))
        ans += tree[pos];
}

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}

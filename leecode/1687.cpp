#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
const int mod = 1e9 + 7;
const int MAX = 2e9 + 7;
const int N = 1e5 + 5;

int diff[N], dp[N];
deque<pair<int, int>> dequ;

int boxDelivering(vector<vector<int>> &boxes, int portsCount, int maxBoxes, int maxWeight)
{
    int n = boxes.size();
    for (int i = 1; i < n; i++)
    {
        diff[i] = diff[i - 1];
        if (boxes[i][0] != boxes[i - 1][0])
            diff[i]++;
    }

    int ans = 0;
    int Boxes = 0;
    int Weight = 0;
    int minj = 0;
    for (int i = 0, j = 0; i < n; i++)
    {
        Boxes += 1;
        Weight += boxes[i][1];
        while (Boxes > maxBoxes || Weight > maxWeight)
        {
            Boxes -= 1;
            Weight -= boxes[j][1];
            if (dequ.front().second == j)
                dequ.pop_front();
            j++;
        }

        dp[i] = (i == 0 ? 2 : diff[i] + 2 + dequ.front().first);

        dequ.push_back(pii((dp[i] - diff[i]), i));
    }
    return dp[n - 1];
}

int main(int argc, char const *argv[])
{
    vector<vector<int>> num = {{2, 4}, {2, 5}, {3, 1}, {3, 2}, {3, 7}, {3, 1}, {4, 4}, {1, 3}, {5, 2}};
    boxDelivering(num, 5, 5, 7);
    return 0;
}

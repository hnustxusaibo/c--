#include <bits/stdc++.h>

using namespace std;

//背包选取，从arr选取任意个值，使得和最接近n
vector<int> backpack(vector<int> &arr, int n)
{
    bool flag[20000] = {};
    vector<int> dp[20000] = {};
    for (int i = n; i >= 0; i--)
        flag[0] = true;
    dp[0] = vector<int>(0);
    int mi = n;
    vector<int> ans;
    for (auto x : arr)
        for (int i = n; i >= 0; i--)
            if (flag[i] == true && flag[i + x] == false)
            {
                flag[i + x] = true;
                dp[i + x] = vector<int>(dp[i]);
                dp[i + x].push_back(x);
                if (mi > abs(i + x - n))
                {
                    mi = abs(i + x - n);
                    ans = vector<int>(dp[i + x]);
                }
            }
    return ans;
}

//分组 从arr中取n-1次背包
vector<vector<int>> clustingArray(vector<int> &arr, int n)
{
    vector<vector<int>> ans;
    for (int i = 0; i < n - 1; i++)
    {
        auto new_arr = backpack(arr, (accumulate(arr.begin(), arr.end(), 0) / (n - i)));
        ans.push_back(new_arr);
        vector<int> result;
        sort(arr.begin(), arr.end());
        sort(new_arr.begin(), new_arr.end());
        std::set_difference(arr.begin(), arr.end(), new_arr.begin(), new_arr.end(), std::back_inserter(result));
        sort(result.begin(), result.end(), std::greater<int>());
        arr = result;
    }
    ans.push_back(arr);
    return ans;
}

//打印分组 以及方差
bool checkArray(vector<vector<int>> &ans)
{
    int n = ans.size();
    int sum = 0;
    for (auto arr : ans)
        for (auto x : arr)
            sum += x;
    double avg = 1.0 * sum / n;
    double variance = 0.0;
    printf("所有数组之和:%d,平均数为%.2f\n", sum, avg);
    for (int i = 0; i < n; i++)
    {
        printf("数组%d: [", i + 1);
        int a_sum = 0;
        for (auto x : ans[i])
        {
            a_sum += x;
            printf("%d,", x);
        }
        variance += fabs(a_sum - avg);
        printf("\b] => 和:%d,平均差:%.2f\n", a_sum, fabs(a_sum - avg));
    }
    printf("\n 平均差为:%.2f\n", variance / n);
    return true;
}

//将一个正整数组a[]分成N组,使每组的数字之和相近.
int main(int argc, char const *argv[])
{
    vector<int> arr = {985, 980, 975, 969, 965, 960, 955, 950, 944, 942, 939, 932, 931, 930, 923, 923, 920, 915, 910,
                       908, 906, 900, 883, 880, 864, 855, 846, 835, 835, 833, 817, 812, 812, 811, 810, 801, 801, 790,
                       786, 777, 776, 765, 760, 737, 732, 730, 726, 719, 708, 705, 701, 697, 694, 681, 679, 639, 636,
                       630, 628, 619, 604, 582, 579, 579, 573, 569, 567, 536, 532, 525, 520, 515, 514, 512, 511, 510,
                       495, 467, 460, 460, 452, 451, 445, 442, 426, 423, 422, 417, 415, 414, 413, 403, 387, 371, 363,
                       357, 354, 347, 343, 343, 341, 337, 327, 312, 310, 293, 292, 288, 281, 273, 261, 258, 248, 237,
                       237, 224, 211, 205, 188, 188, 184, 180, 175, 174, 170, 162, 158, 157, 151, 149, 146, 139, 135,
                       133, 124, 122, 107, 106, 97,  97,  95,  75,  72,  63,  60,  45,  42,  42,  38,  32};

    int n = 8;
    auto ans = clustingArray(arr, n);
    checkArray(ans);
    return 0;
}

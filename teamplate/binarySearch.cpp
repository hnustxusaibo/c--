#include <bits/stdc++.h>

using namespace std;

int binarySearch(vector<int> &nums, int target)
{
    int l, r;
    l = 0, r = nums.size();
    while (l <= r)
    {
        int m = (l + r) >> 1;
        if (nums[m] == target)
        {
            return m;
        }
        if (nums[m] < target)
            l = m + 1;
        if (nums[m] > target)
            r = m - 1;
    }
    return -1;
}

int search(vector<int> &nums, int target)
{
    return binarySearch(nums, target);
}
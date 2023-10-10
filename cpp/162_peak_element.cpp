#include <bits/stdc++.h>
using namespace std;
int res = INT_MIN;
int recurs(vector<int> &nums, int lb, int ub)
{
    if (res != INT_MIN)
        return 0;

    int mid = lb + (ub - lb) / 2;
    if (mid + 1 > nums.size() - 1 && nums.at(mid) > nums.at(mid - 1))
    {
        res = nums.at(mid);
        return 0;
    }

    if (nums.at(mid) > nums.at(mid + 1) && mid - 1 < 0)
    {
        res = nums.at(mid);
        return 0;
    }

    // not much here
    if (mid - 1 < 0 || mid + 1 > nums.size() - 1)
        return 0;

    if (nums.at(mid) > nums.at(mid - 1) && nums.at(mid) > nums.at(mid + 1))
    {
        res = nums.at(mid);
        return 0;
    }
    if (ub - lb <= 2)
        return 0;

    return recurs(nums, mid, ub) + recurs(nums, lb, mid);
}
int findPeakElement(vector<int> &nums)
{
    if (nums.size() == 1)
        return nums.at(0);
    if (nums.size() == 2)
    {
        return nums.at(0) > nums.at(1) ? nums.at(0) : nums.at(1);
    }
    if (nums.at(0) > nums.at(1))
        return nums.at(0);
    if (nums.at(nums.size() - 1) > nums.at(nums.size() - 2))
        return nums.at(nums.size() - 1);
    recurs(nums, 0, nums.size() - 1);
    return res;
}
int main()
{
    vector<int> nums{1, 2, 3, 1};
    cout << findPeakElement(nums) << "yes sir";

    return 0;
}

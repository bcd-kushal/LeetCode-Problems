#include <vector>
using namespace std;

class Solution {
private:
    int minRemovals(vector<int>& arr, int start, int end, int dir, int limit) {
        vector<int> lis;
        for (int i = start; (dir == -1) ? (i >= end) : (i <= end); i += dir)
            if (arr[i] < limit) {
                if (lis.empty() || lis[lis.size() - 1] < arr[i])
                    lis.push_back(arr[i]);
                else {
                    auto it = lower_bound(lis.begin(), lis.end(), arr[i]);
                    if (it != lis.end())
                        lis[it - lis.begin()] = arr[i];
                }
            }

        return (dir == -1 ? start - end : end - start) + 1 - lis.size();
    }

public:
    int minimumMountainRemovals(vector<int>& nums) {
        int minRemove = nums.size(), L, R;
        for (int i = 1; i < nums.size() - 1; i += 1) {
            L = minRemovals(nums, 0, i - 1, 1, nums[i]);
            R = minRemovals(nums, nums.size() - 1, i + 1, -1, nums[i]);
            minRemove = min(minRemove, (i == L ? 1000 : L) + (nums.size() - i - 1 == R ? 1000 : R));
        }

        return minRemove;
    }
};
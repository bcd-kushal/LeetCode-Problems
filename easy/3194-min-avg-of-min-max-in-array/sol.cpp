#include <vector>
#include <algorithm>
#include <limits.h>
using namespace std;

class Solution {
public:
    double minimumAverage(vector<int>& nums) {
        double minAvg = INT_MAX;
        sort(nums.begin(),nums.end());

        for(int low = 0, high = nums.size()-1; low < high; low+=1, high-=1)
            minAvg = min(minAvg,(double)(nums[low]+nums[high]));

        return minAvg/2;
    }
};
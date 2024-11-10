#include <vector>
#include <limits.h>
#include <cmath>
using namespace std;

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double sum = 0.0, maxSum = INT_MIN;
        int left = 0, right = k-1;
        for(int i=0;i<=right;i+=1)
            sum += nums[i];

        maxSum = max(maxSum, sum);
        right += 1;
        left += 1;

        for(; right<nums.size(); right+=1,left+=1) {
            sum -= nums[left-1];
            sum += nums[right];
            maxSum = max(maxSum, sum);
        }

        return maxSum/k;
    }
};
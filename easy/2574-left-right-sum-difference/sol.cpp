#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        vector<int> leftSum(nums.size(),0), rightSum(nums.size(),0);

        for(int i=1;i<nums.size();i+=1) {
            leftSum[i] = leftSum[i-1] + nums[i-1];
            rightSum[nums.size()-1-i] = rightSum[nums.size()-i] + nums[nums.size()-i];
        }

        for(int i=0;i<nums.size();i+=1)
            leftSum[i] = abs(leftSum[i] - rightSum[i]);
        
        return leftSum;
    }
};
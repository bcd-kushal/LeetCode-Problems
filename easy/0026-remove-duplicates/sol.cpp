#include <vector>
using namespace std;

class Solution
{
public:
    int removeDuplicates(vector<int>& nums) {
        int low = 0, high = 1;
        for(;high<nums.size();high+=1) {
            if(nums[high]==nums[low])   
                continue;
            low += 1;
            nums[low] = nums[high];
        }

        return low+1;
    }
};
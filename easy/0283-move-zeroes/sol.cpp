#include <vector>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int left = 0;
        for(int right = 0;right<nums.size();right+=1) {
            while(left < nums.size() && nums[left] != 0)
                left += 1;
            
            if(left >= nums.size()-1) 
                return;

            while(right <= left)
                right += 1;
            
            if(nums[right] != 0) {
                nums[left] = nums[right];
                nums[right] = 0;
            }
        }
    }
};
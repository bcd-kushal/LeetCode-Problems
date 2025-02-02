#include <vector>
using namespace std;

class Solution {
    public:
    bool check(vector<int>& nums) {
        int curr = nums[0];
        bool dipped = false, check = false;

        for(int i=1;i<nums.size(); i+=1) {
            if(nums[i] , nums[i-1]) {
                if(dipped)  return false;
                else        dipped = true;

                check = true; 
            }

            if(check && nums[i] > nums[0])
                return false;
        }

        return true;
    }
}
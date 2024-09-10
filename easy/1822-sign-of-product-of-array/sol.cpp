#include <vector>
using namespace std;

class Solution {
public:
    int arraySign(vector<int>& nums) {
        bool negative = false;
        int len = nums.size();

        for(int i=0; i<len;i++) {
            if(nums[i]==0)  return 0;
            if(nums[i] < 0) negative = !negative;
        }

        return negative ? -1 : 1;
    }
};
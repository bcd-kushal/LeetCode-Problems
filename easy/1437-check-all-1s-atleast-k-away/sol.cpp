#include <vector>
using namespace std;

class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int left = -1, right = 0;
        bool allCorrectlyAway = true;

        for(; right<nums.size(); right+=1) {
            if(nums[right]==1 && left==-1)
                left = right;
            else if(nums[right]==1) {
                allCorrectlyAway &= right-left-1 >= k ? true : false;
                left = right;
            }
        }

        return allCorrectlyAway;
    }
};
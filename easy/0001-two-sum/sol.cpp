#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
    public:
        vector<int> twoSum(vector<int>& nums, int target) {
            unordered_map<int,int> map;
            for(int i=0;i<nums.size();i++) {
                if(map.count(nums[i]) > 0)
                    return {map[nums[i]], i};
    
                map[target-nums[i]] = i;
            }
    
            return {};
        }
};
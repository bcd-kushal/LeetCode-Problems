#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        if(nums.size()==0)  return {};
        if(nums.size()==1)  return { to_string(nums[0]) };

        vector<string> ranges;
        int low = 0;

        for(int i=1;i<nums.size();i+=1) {
            if(nums[i]==nums[i-1]+1)    
                continue;
            
            if(low==i-1)    ranges.push_back(to_string(nums[i-1]));
            else            ranges.push_back(to_string(nums[low]) + "->" + to_string(nums[i-1]));
            
            low = i;
        }

        if(low==nums.size()-1)      ranges.push_back(to_string(nums[nums.size()-1]));
        else                        ranges.push_back(to_string(nums[low]) + "->" + to_string(nums[nums.size()-1]));

        return ranges;
    }
};
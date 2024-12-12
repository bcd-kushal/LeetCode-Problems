#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int mostFrequent(vector<int>& nums, int key) {
        unordered_map<int,int> counts;
        int maxTarget = 0;

        for(int i=0;i<nums.size()-1;i+=1) {
            if(nums[i]==key) {
                if(counts.find(nums[i+1])==counts.end())    
                    counts[nums[i+1]] = 1;
                else    counts[nums[i+1]] += 1;

                if(counts[maxTarget] < counts[nums[i+1]]) 
                    maxTarget = nums[i+1];
            }
        }

        return maxTarget;
    }
};
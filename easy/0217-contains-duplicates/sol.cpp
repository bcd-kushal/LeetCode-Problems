#include <unordered_set>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> store;
        for(int i=0;i<nums.size();i+=1)
            if(store.find(nums[i])!=store.end())    return true;
            else                                    store.insert(nums[i]);
        
        return false;
    }
};
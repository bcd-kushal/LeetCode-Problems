#include <vector>
using namespace std;

class Solution {
private:
    bool parity(int x) { return x%2 == 0; }

public:
    bool isArraySpecial(vector<int>& nums) {
        bool lastParity = parity(nums[0]), currParity;

        for(int i=1;i<nums.size();i+=1) {
            currParity = parity(nums[i]);
            if(lastParity == currParity)
                return false;
                
            lastParity = currParity;
        }

        return true;
    }
}
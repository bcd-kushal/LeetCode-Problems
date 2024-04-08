            
#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int findDuplicate(vector<int>& nums) {
            int hare = nums[0];
            int tortoise = nums[0];

            while(true) {
                hare = nums[nums[hare]];
                tortoise = nums[tortoise];
                if(tortoise==hare)
                    break;
            }

            hare = nums[0];

            while(hare!=tortoise) {
                hare = nums[hare];
                tortoise = nums[tortoise];
            }

            return hare;
        }
};

int main() {
    vector<int> nums = {1,3,4,2,2};
    Solution ob;

    auto start = chrono::steady_clock::now();
    int n = ob.findDuplicate(nums);
    auto end = chrono::steady_clock::now();

    cout << n;
    cout << "\n... time taken = " << chrono::duration_cast<chrono::milliseconds>(end-start).count() << "ms";
    
    return 0;
}
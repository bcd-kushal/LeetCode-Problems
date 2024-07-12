#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int maximumGap(vector<int>& nums) {
            if(nums.size() < 2)
                return 0;

            sort(nums.begin(),nums.end());
            int maxGap = INT_MIN;

            for(int i=0; i<nums.size()-1; i++) 
                maxGap = max(maxGap, nums[i+1]-nums[i]);

            return maxGap;
        }
};

int main() {
    vector<int> nums = {2,6,1,7,3,0,9};
    Solution ob;

    auto start = chrono::steady_clock::now();
    cout << ob.maximumGap(nums);
    auto end = chrono::steady_clock::now();

    cout << "\n... time taken: " << chrono::duration_cast<chrono::milliseconds>(end-start).count() << "ms";
    return 0;
}

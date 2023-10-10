/*
Given an integer array nums representing the amount of money of each house,
return the maximum amount of money you can rob tonight without alerting the police.

Example 1:
Input: nums = [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
Total amount you can rob = 1 + 3 = 4.

Example 2:
Input: nums = [2,7,9,3,1]
Output: 12
Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 (money = 1).
Total amount you can rob = 2 + 9 + 1 = 12.

Constraints:
1 <= nums.length <= 100
0 <= nums[i] <= 400
*/

#include <bits/stdc++.h>
using namespace std;


    int rob(vector<int>& nums) {
        int rob_value = 0;
        for(int i=0;i<nums.size();i++){
            if(i<1){
                rob_value = nums[i];
                continue;
            }
            if(i<2)
                nums[i] = (rob_value = max(nums[i],nums[i-1]));
            else
                nums[i] = (rob_value = max(nums[i]+nums[i-2],nums[i-1]));
        }

        return rob_value;
    }
    


/*
Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.
If target is not found in the array, return [-1, -1].
You must write an algorithm with O(log n) runtime complexity.

Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]
Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]
Input: nums = [], target = 0
Output: [-1,-1]

Constraints:
0 <= nums.length <= 105
-109 <= nums[i] <= 109
nums is a non-decreasing array.
-109 <= target <= 109
*/

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        pair<int,int> result;

        result.first=-1;
        result.second=-1;

        if(nums.size()<2 || target<nums[0] || target>nums.back()){
            if(nums.size()==1 && nums[0]==target){
                result.first=0;
                result.second=0;
            }
            return vector<int> {result.first,result.second};
        }

        if(nums.front()==nums.back() && nums.front()==target){
            result.first=0;
            result.second=nums.size()-1;
            return vector<int> {result.first,result.second};
        }


        int low=0, high=nums.size()-1;
        int i=0;

        while(low<=high){
            int mid = low + (int)((high-low)/2);

            if(nums[mid]==target){
                while((mid-i>=0 && nums[mid-i]==target) || (mid+i<nums.size() && nums[mid+i]==target)){
                    if(mid-i>=0 && nums[mid-i]==target)
                        result.first = mid-i;
                    if(mid+i<nums.size() && nums[mid+i]==target)
                        result.second = mid+i;
                    i+=1;
                }
                return vector<int> {result.first,result.second};
            }

            if(target<nums[mid]){
                high=mid-1;
                continue;
            }

            low = mid+1;
        }

        return vector<int> {result.first,result.second};

    }
};

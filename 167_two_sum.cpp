/*
Given a 1-indexed array of integers numbers that is already sorted in
non-decreasing order, find two numbers such that they add up to a specific
target number. Let these two numbers be numbers[index1] and numbers[index2]
where 1 <= index1 < index2 < numbers.length.
Return the indices of the two numbers, index1 and index2, added by one as
an integer array [index1, index2] of length 2.
The tests are generated such that there is exactly one solution. You may
not use the same element twice.
Your solution must use only constant extra space.

Input: numbers = [2,7,11,15], target = 9
Output: [1,2]
Explanation: The sum of 2 and 7 is 9. Therefore, index1 = 1, index2 = 2. We return [1, 2].
Input: numbers = [2,3,4], target = 6
Output: [1,3]
Explanation: The sum of 2 and 4 is 6. Therefore index1 = 1, index2 = 3. We return [1, 3].
Input: numbers = [-1,0], target = -1
Output: [1,2]
Explanation: The sum of -1 and 0 is -1. Therefore index1 = 1, index2 = 2. We return [1, 2].

Constraints:
2 <= numbers.length <= 3 * 104
-1000 <= numbers[i] <= 1000
numbers is sorted in non-decreasing order.
-1000 <= target <= 1000
The tests are generated such that there is exactly one solution.
*/

class Solution {
public:
    int findIndex(vector<int>& nums,int low,int high, int target){
        while(low<=high){
            int mid = low + (int)((high-low)/2);

            if(target==nums[mid])
                return mid;

            if(target<nums[mid]){
                high=mid-1;
                continue;
            }

            if(target>nums[mid]){
                low=mid+1;
                continue;
            }
        }

        return -1;
    }

    vector<int> twoSum(vector<int>& numbers, int target) {
        if(numbers.size()==2)
            return vector<int> {1,2};

        for(int i=0;i<numbers.size()-1;i++){
            int second_index = findIndex(numbers,i+1,numbers.size()-1,target-numbers[i]);
            if(second_index==-1)
                continue;

            return vector<int> {i+1,second_index+1};
        }

        return vector<int> {0,0};
    }
};

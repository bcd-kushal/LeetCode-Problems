/*
Given an integer array nums and an integer k, return the kth largest element in the array.
Note that it is the kth largest element in the sorted order, not the kth distinct element.
You must solve it in O(n) time complexity.

Input: nums = [3,2,1,5,6,4], k = 2
Output: 5
Input: nums = [3,2,3,1,2,4,5,5,6], k = 4
Output: 4

Constraints:
1 <= k <= nums.length <= 105
-104 <= nums[i] <= 104
*/

class Solution {

    public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> myHeap;
        for(auto const &num: nums)
            myHeap.push(num);

        //int ans;
        while(k>1){
            myHeap.pop();
            k-=1;
        }
        return myHeap.top();
    }
};

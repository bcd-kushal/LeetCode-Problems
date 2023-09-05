/*
Given an array of positive integers nums, remove the smallest subarray
(possibly empty) such that the sum of the remaining elements is
divisible by p. It is not allowed to remove the whole array.

Return the length of the smallest subarray that you need to remove,
or -1 if it's impossible.

Example 1:
Input: nums = [3,1,4,2], p = 6
Output: 1
Explanation: The sum of the elements in nums is 10, which is not divisible by 6. We can remove the subarray [4], and the sum of the remaining elements is 6, which is divisible by 6.
Example 2:
Input: nums = [6,3,5,2], p = 9
Output: 2
Explanation: We cannot remove a single element to get a sum divisible by 9. The best way is to remove the subarray [5,2], leaving us with [6,3] with sum 9.

Constraints:
1 <= nums.length <= 105
1 <= nums[i] <= 109
1 <= p <= 109
*/

int minSubarray(vector<int>& nums, int p) {
        int minLen=0;
        int extra=0;

        for(auto num: nums)
            extra=(extra+num)%p;

        if(extra==0)
            return -1;

        while(extra>0){
            sort(nums.begin(),nums.end());
            if(nums[nums.size()-1]==extra){
                extra-=nums[nums.size()-1];
                minLen+=1;
                break;
            }
            for(int i=0;i<nums.size()-1;i++){
                if(nums[i]==extra){
                    extra-=nums[i];
                    minLen+=1;
                    break;
                }
                if(nums[i]<extra && nums[i+1]>extra){
                    extra-=nums[i];
                    minLen+=1;
                    nums.erase(nums.begin()+i);
                    break;
                }
            }

            if(extra==0)
                break;
        }

        return minLen;
    }

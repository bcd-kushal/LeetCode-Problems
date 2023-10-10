/*
Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.
You must write an algorithm that runs in O(n) time.

Input: nums = [100,4,200,1,3,2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.

Input: nums = [0,3,7,2,5,8,4,6,0,1]
Output: 9

Constraints:
0 <= nums.length <= 105
-109 <= nums[i] <= 109
*/

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,bool> hash;

        for(int num: nums)
            hash[num]=true;

        for(auto &el: hash)
            if(hash.count(el.first-1)>0)
                el.second=false;

        int count = 1, max_len = 0;

        for(auto const &el: hash){
            if(el.second==true){
                int temp = el.first;

                while(hash.count(temp+1)>0){
                    count+=1;
                    temp+=1;
                }

                if(count>max_len)
                    max_len = count;

                count = 1;
            }
        }

        return max_len;
    }
};

/*
Given an integer array nums where the elements are sorted in ascending order, convert it
to a height-balanced binary search tree.

Input: nums = [-10,-3,0,5,9]
Output: [0,-3,9,-10,null,5]
Explanation: [0,-10,5,null,-3,null,9] is also accepted

Input: nums = [1,3]
Output: [3,1]
Explanation: [1,null,3] and [3,1] are both height-balanced BSTs.

Constraints:
1 <= nums.length <= 104
-104 <= nums[i] <= 104
nums is sorted in a strictly increasing order.
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode *bin_sort(vector<int> &nums,int low,int high){
        if(low>high)
            return nullptr;

        int mid = low + (int)((high-low)/2);
        TreeNode *x = new TreeNode(nums.at(mid),bin_sort(nums,low,mid-1),bin_sort(nums,mid+1,high));
        return x;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return bin_sort(nums,0,nums.size()-1);
    }
};

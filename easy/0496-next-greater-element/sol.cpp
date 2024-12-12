#include <vector>  
#include <unordered_map>
#include <stack>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> nextGreater(nums2.size(), -1);
        vector<int> ans(nums1.size(), -1);
        unordered_map<int,int> map;
        stack<int> st;

        for(int i=0;i<nums2.size();i+=1) {
            map[nums2[i]] = i;

            if(st.empty())  st.push(i);
            else {
                while(!st.empty() && nums2[st.top()] < nums2[i]) {
                    nextGreater[st.top()] = nums2[i];
                    st.pop();
                }
                st.push(i);
            }
        }
        
        for(int i=0;i<nums1.size();i+=1) 
            ans[i] = nextGreater[map[nums1[i]]];

        return ans;
    }
};
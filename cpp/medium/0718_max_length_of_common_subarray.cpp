#include <bits/stdc++.h>
using namespace std;

class Solution {
    private:
        pair<int,int> getMaxCommonDuration(vector<int> &arr, int pos, vector<int>::iterator itr, vector<int>::iterator end) {
            int lb = pos, ub = INT_MIN;
            while(pos<arr.size() && itr!=end && arr[pos]==*itr) {
                ub = pos;
                pos+=1;
                itr+=1;
            }

            if(ub-lb<0)    
                return make_pair(-1,-1);

            return make_pair(lb,ub);
        }

    public:
        int findLength(vector<int> &nums1, vector<int> &nums2) {
            unordered_map<int,vector<int>> map;
            int max_common_length = INT_MIN;

            for(int i=0; i<nums1.size(); i++) 
                map[nums1[i]].push_back(i);
            
            for(int num=0; num<nums2.size(); num++) {
                if(map.count(nums2[num]) > 0)
                    for(auto j: map[nums2[num]]) {
                        if(max_common_length==min(nums1.size(),nums2.size()))
                            break;
                        auto p = getMaxCommonDuration(nums2,num,nums1.begin()+j,nums1.end());
                        if(p.second-p.first>=0) {
                            max_common_length = max(max_common_length, p.second-p.first+1);
                        }
                    }
            }

            if(max_common_length <= 0)  
                return 0;
                
            return max_common_length;
        }
};

int main() {
    vector<int> nums1 = {0,0,0,0,0},
                nums2 = {0,0,0,0,0};
    
    Solution obj;

    auto start = chrono::steady_clock::now();
    int len = obj.findLength(nums1,nums2);
    auto end = chrono::steady_clock::now();

    cout << len;
    cout << "\n... time taken: " << chrono::duration_cast<chrono::milliseconds>(end-start).count() << "ms";

    return 0;
}
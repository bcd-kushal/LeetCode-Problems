#include <bits/stdc++.h>
using namespace std;

class Subarray {
    private:
        pair<int,int> kadaneAlgo(vector<int>::iterator itr, vector<int>::iterator end, int offset, int target) {
            int max_so_far = 0,
                global_max =INT_MIN,
                lb=0;
            pair<int,int> ans = make_pair(INT_MAX,INT_MAX);

            while(itr!=end) {
                if(max_so_far==0)
                    lb = offset;
                max_so_far += *itr;
                global_max = max(global_max, max_so_far);
                if(global_max>=target) {
                    ans = make_pair(lb,offset);
                    break;
                }
                if(max_so_far < 0)
                    max_so_far = 0;
                
                itr+=1;
                offset+=1;
            }

            if(ans.first==INT_MAX) 
                return make_pair(-1,-1);
            
            return ans;
        }

    public:
        int minSubArrayLen(int target, vector<int>& nums) {
            int max_so_far = 0;
            int ans = INT_MAX;

            for(int i=0; i<nums.size(); i++) {
                auto p = kadaneAlgo(nums.begin()+i, nums.end(), i, target);
                if(p.first >= 0) 
                    ans = min(ans, p.second-p.first+1);
            }

            return ans == INT_MAX ? 0 : ans;
        }
};

int main() {
    vector<int> nums = {1,1,1,1,1};
    int target = 11;
    Subarray sub;

    auto start = chrono::steady_clock::now();
    int n = sub.minSubArrayLen(target, nums);
    auto end = chrono::steady_clock::now();

    cout << n;
    cout << "\n... time taken = " << chrono::duration_cast<chrono::milliseconds>(end-start).count() << "ms";
    
    return 0;
}
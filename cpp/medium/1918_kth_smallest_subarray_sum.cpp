#include <bits/stdc++.h>
using namespace std;

class SubarraySums {
    private:
        int arrSum(vector<int> &arr) {
            if(!arr.size())     return 0;
            
            int sum = 0;
            for(int i: arr)
                sum += i;
            
            return sum;
        }

    public:
        int kthSmallestSum(vector<int> &nums, int k) {
            unordered_map<int,vector<vector<int>>> map;
            int n = nums.size();
            
            for(int pos=0; pos<n; pos++) {
                for(int i=1;i<=n-pos;i++)
                    map[nums[pos]].push_back({nums[pos]});
                for(int i=0;i<n;i++) {
                    auto arr = map[nums[i]];
                    for(int j=arr.size()-1;j>=0;j--) {
                        arr[j].push_back(nums[pos]);
                    }
                }
            }

        }
};

int main() {
    vector<int> nums = {1,2,3};
    int k = 4;

    SubarraySums sub;

    auto start = chrono::steady_clock::now();
    int result = sub.kthSmallestSum(nums,k);
    auto end = chrono::steady_clock::now();

    cout << result << endl;
    cout << "\n... time taken: " << chrono::duration_cast<chrono::milliseconds>(end-start).count() << "ms";
}

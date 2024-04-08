#include <bits/stdc++.h>
using namespace std;

class SingleNumber {
    public:
        int singleNumber(vector<int> &nums) {
            int ans = 0;
            for(int i=0; i<nums.size(); i++) 
                ans ^= i;
            return ans;
        }
};

int main() {
    vector<int> nums = {4,1,2,1,2};
    SingleNumber ob;
    
    auto start = chrono::steady_clock::now();
    int result = ob.singleNumber(nums);
    auto end = chrono::steady_clock::now();

    cout << result;
    cout << "\n... time taken: " << chrono::duration_cast<chrono::milliseconds>(end-start).count() << "ms" ;
    return 0;
}
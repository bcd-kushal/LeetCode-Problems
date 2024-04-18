#include <bits/stdc++.h>
using namespace std;

class Numbers {
    private:

    public: 
        int SingleNumber(vector<int> &nums) {
            int ones_count = 0, twos_count = 0;

            for(int i=0; i<nums.size(); i++) {
                ones_count = (ones_count ^ nums[i]) & (~twos_count);
                twos_count = (twos_count ^ nums[i]) & (~ones_count);
            }

            return ones_count;
        }
};

int main() {
    vector<int> nums = {0,1,0,1,0,1,99};
    Numbers number;

    auto start = chrono::steady_clock::now();
    cout << number.SingleNumber(nums) ;
    auto end = chrono::steady_clock::now();

    cout << "\n... time taken: " << chrono::duration_cast<chrono::milliseconds>(end-start).count() << "ms";
    return 0;
}
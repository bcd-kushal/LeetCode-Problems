#include <vector>
#include <utility>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> heap;

        for (int i = 0; i < nums.size(); i += 1)
            heap.push({ nums[i], i });

        for (; k > 0; k -= 1) {
            pair<int, int> x = heap.top();
            heap.pop();
            nums[x.second] = x.first * multiplier;
            heap.push({ x.first * multiplier, x.second });
        }

        return nums;
    }
};
#include <queue>
#include <vector>
#include <cmath>
using namespace std;

class Solution
{
public:
    long long pickGifts(vector<int>& gifts, int k) {
        long long sum = 0, deducted = 0;
        int largest, remainder;
        priority_queue<int> heap;

        for(int i=0;i<gifts.size();i+=1) {
            sum += gifts[i];
            heap.push(gifts[i]);
        }

        for(int i=0;i<k;i+=1) {
            largest = heap.top();
            heap.pop();

            remainder = floor(sqrt(largest));
            deducted += largest - remainder;
            heap.push(remainder);
        }

        return sum - deducted;
    }
};
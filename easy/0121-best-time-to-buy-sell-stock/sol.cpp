#include <vector>
#include <limits.h>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()==1)   
            return 0;

        int currHigh = INT_MIN, profit = 0;
        for(int i = prices.size()-2; i >= 0; i -= 1) {
            currHigh = max(currHigh, prices[i+1]);
            profit = max(profit, currHigh - prices[i]);
        }

        if(profit <= 0) 
            return 0;
        
        return profit;
    }
};
#include <cmath>
#include <vector>
using namespace std;

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        if(cost.size()==1)  
          return cost[0];
          
        vector<int> dp(cost.size()+2, 0);
        
        for(int i=cost.size()-1;i>=0;i-=1)
          dp[i] = cost[i] + min(dp[i+1],dp[i+2]);
        
        return min(dp[0],dp[1]);
    }
};

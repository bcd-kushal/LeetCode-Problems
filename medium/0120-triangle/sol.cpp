#include <vector>
#include <limits.h>
using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int>> dp(2,vector<int>(triangle[triangle.size()-1].size()+1, INT_MAX));
        int maxIndex = 1, curr = 1, shortest = INT_MAX;
        dp[0][0] = triangle[0][0];

        for(int i=1;i<triangle.size();i+=1) {
            for(int j=0;j<=maxIndex;j+=1) {
                dp[curr][j] = triangle[i][j] + min(j-1>=0?dp[curr^1][j-1]:INT_MAX,dp[curr^1][j]);
                if(i==triangle.size()-1)
                    shortest = min(shortest,dp[curr][j]);
            }
            maxIndex += 1;
            curr ^= 1;
        }

        return shortest==INT_MAX ? dp[0][0] : shortest;
    }
};
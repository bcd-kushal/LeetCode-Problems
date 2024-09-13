#include <vector>
#include <limits.h>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int maxArea = INT_MIN;
        int local_min = INT_MAX;
        int len = heights.size();

        for(int i=0;i<len;i++) {
            local_min = heights[i];
            for(int j=i;j<len;j++) {
                int l = j-i+1;
                int b = min(heights[j],local_min);
                local_min = b;

                maxArea = max(maxArea, l*b);
            }
        }

        return maxArea;
    }
};
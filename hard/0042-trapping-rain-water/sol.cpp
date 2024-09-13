#include <vector>
#include <limits.h>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int len = height.size();
        vector<int> left(len), 
                    right(len);
        int waterTrapped = 0;

        for(int i=0, j=len-1; i < len, j >= 0; i++, j--) {
            int l = i==0 ? INT_MIN : left[i-1];
            left[i] = max(l ,height[i]);

            int r = j==len-1 ? INT_MIN : right[j+1];
            right[j] = max(r, height[j]);
        }

        for(int i=0; i<len; i++) 
            waterTrapped += min(left[i],right[i]) - height[i];
        
        return waterTrapped;
    }
};
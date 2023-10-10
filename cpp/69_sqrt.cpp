/*
Given a non-negative integer x, return the square root of x rounded down to the nearest
integer. The returned integer should be non-negative as well.
You must not use any built-in exponent function or operator.

Input: x = 4
Output: 2
Explanation: The square root of 4 is 2, so we return 2.
Input: x = 8
Output: 2
Explanation: The square root of 8 is 2.82842..., and since we round it down to the nearest integer, 2 is returned.


Constraints:
0 <= x <= 231 - 1
*/

class Solution {
public:
    int mySqrt(int x) {
        if(x==0)            return 0;
        if(x>=1 && x<=3)    return 1;
        if(x>=4 && x<=5)    return 2;

        int low = 1, high = (int)(x/2);
        int boundary = 0,ans = 0;

        while(low<=high){
            int mid = low+(int)((high-low)/2);
            if(mid==x/mid)
                return mid;

            if(mid>x/mid){
                boundary = mid;
                high = mid-1;
                continue;
            }

            low = mid+1;
            ans = mid;
        }

        return ans;
    }
};

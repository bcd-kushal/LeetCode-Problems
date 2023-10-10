/*
Write a function that takes the binary representation of an unsigned integer
and returns the number of '1' bits it has (also known as the HAMMING WEIGHT).

Input: n = 00000000000000000000000010000000
Output: 1
Input: n = 00000000000000000000000000001011
Output: 3
Input: n = 11111111111111111111111111111101
Output: 31


Constraints:
The input must be a binary string of length 32.
*/

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int ans = 0;
        while(n>0){
            ans+=((n%2)==1?1:0);
            n>>=1;
        }
        return ans;
    }
};

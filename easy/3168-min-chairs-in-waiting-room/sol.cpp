#include <string>
#include <algorithm>
#include <limits.h>
using namespace std;

class Solution {
public:
    int minimumChairs(string s) {
        int minChairs = INT_MIN, 
            local_min = 0;
        
        for(int i=0;i<s.size();i++)
            if(s[i]=='E') {
                local_min += 1;
                minChairs = max(local_min,minChairs);
            }
            else
                local_min -= 1;
        
        return minChairs;
    }
};
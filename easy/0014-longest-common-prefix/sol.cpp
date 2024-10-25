#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(), strs.end());
        int lcpIndex = -1;

        for(int i=0;i<strs[0].size();i+=1)
            if(i<strs[strs.size()-1].size() && strs[strs.size()-1][i]==strs[0][i])
                lcpIndex = i;
            else
                break;
        
        return lcpIndex < 0 ? "" : strs[0].substr(0,lcpIndex+1);
    }
};
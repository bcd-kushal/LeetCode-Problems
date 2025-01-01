#include <cmath>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int maxScore(string s) {
        vector<vector<int>> pre(2, vector<int>(s.size(),0));
        int maxStringScore = 0;

        for(int i=0;i<s.size();i+=1) {
            int backIndex = s.size()-1-i;
            pre[0][i] = (i>0 ? pre[0][i-1] : 0) + (s[i] == '0' ? 1 : 0);
            pre[1][backIndex] = (backIndex<s.size()-1 ? pre[1][backIndex+1] : 0) + (s[backIndex] == '1' ? 1 : 0);
        }

        for(int i=0;i<s.size()-1;i+=1)
            maxStringScore = max(maxStringScore, pre[0][i]+pre[1][i+1]);

        return maxStringScore;
    }
};
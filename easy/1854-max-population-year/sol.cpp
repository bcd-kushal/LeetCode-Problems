#include <vector>
using namespace std;

class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        vector<int> alive(101, 0);
        int maxPIndex = 0;

        for(int i=0;i<logs.size();i+=1) {
            alive[logs[i][0] - 1950] += 1;
            alive[logs[i][1] - 1950] -= 1;
        }

        for(int i=1;i<alive.size();i+=1) {
            alive[i] += alive[i-1];
            if(alive[i] > alive[maxPIndex])
                maxPIndex = i;
        }
        
        return maxPIndex + 1950;
    }
};
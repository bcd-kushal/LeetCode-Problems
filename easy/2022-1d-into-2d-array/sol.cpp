#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        int size = original.size();
        
        if(m*n != size) 
            return {};

        int curr = 0;
        vector<vector<int>> dda(m, vector<int>(n, 0));

        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++) {
                dda[i][j] = original[curr];
                curr++;
            }

        return dda;
    }
};
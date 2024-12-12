#include <vector>
#include <set>
using namespace std;

class Solution {
private:
    int operateExtents(vector<vector<int>> &heights, int start, int end, int height) {
        int maxLocalHeight = -1;

        for (int i = start; i < heights.size(); i += 1) {
            maxLocalHeight = max(maxLocalHeight, heights[i][2]);
            if(i + 1 < heights.size() && end > heights[i + 1][0]) {
                heights[i][1] = heights[i + 1][0];
            }
            else {
                heights[i][1] = end;
                end = i;
                break;
            }
        }

        for (int i = start; i <= end; i += 1) 
            heights[i][2] = height + maxLocalHeight;

        return height + maxLocalHeight;
    }

public:
    vector<int> fallingSquares(vector<vector<int>>& positions) {
        set<int> coords;
        unordered_map<int, int> indices;
        vector<int> maxHeight(positions.size(), 0);
        vector<vector<int>> heights;

        int newHeight, i=0;

        for (; i < positions.size();i+=1)
            coords.insert(positions[i][0]);

        i = 0;
        for (auto it = coords.begin(); it != coords.end(); it++, i += 1) {
            heights.push_back({*it, (*it)+1, 0});
            indices[*it] = i;
        }

        for (int i = 0; i < positions.size();i+=1) {
            newHeight = operateExtents(heights, indices[positions[i][0]], positions[i][0]+positions[i][1], positions[i][1]);
            if(i==0 || newHeight >= maxHeight[i-1])
                maxHeight[i] = newHeight;
            else
                maxHeight[i] = maxHeight[i - 1];
        }

        return maxHeight;
    }
};
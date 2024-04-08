#include <vector>
#include <queue>
#include <stdlib.h>
#include <iostream>

using namespace std;

class Solution {
private:
    bool checkNotVisited(vector<pair<int,int>> V, pair<int,int> el) {
        for(auto it = V.begin(); it!=V.end(); it++)
            if(*it==el)
                return false;
        return true;
    }
    
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int rows = image.size();
        int cols = image[0].size();
        int pixel_to_change = image[sr][sc];
        
        queue<pair<int,int>> Q;
        vector<pair<int,int>> Visited;
        
        Q.push(make_pair(sr,sc));
        
        while(!Q.empty()) {
            
            // update co-ordinates
            sr = Q.front().first;
            sc = Q.front().second;
            
            // process adjacent elements and push into Q
            if(sr+1<rows && checkNotVisited(Visited,make_pair(sr+1,sc)) && image[sr+1][sc]==pixel_to_change)       Q.push(make_pair(sr+1,sc));
            if(sr-1>=0   && checkNotVisited(Visited,make_pair(sr-1,sc)) && image[sr-1][sc]==pixel_to_change)       Q.push(make_pair(sr-1,sc));
            if(sc+1<rows && checkNotVisited(Visited,make_pair(sr,sc+1)) && image[sr][sc+1]==pixel_to_change)       Q.push(make_pair(sr,sc+1));
            if(sc-1>=0   && checkNotVisited(Visited,make_pair(sr,sc-1)) && image[sr][sc-1]==pixel_to_change)       Q.push(make_pair(sr,sc-1));
            
            
            // color this position
            image[sr][sc] = color;
            
            // remove this pixel from Q
            Visited.push_back(Q.front());
            Q.pop();
                      
        }
        
        return image;

    }
};
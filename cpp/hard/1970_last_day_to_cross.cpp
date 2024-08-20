#include <bits/stdc++.h>
using namespace std;

class LastDay {
private:
    bool f(int row,int col,int mid,vector<vector<int>> &cells){
        vector<vector<int>>grid(row,vector<int>(col));
        for(int i = 0;i < mid;i++)
            grid[cells[i][0]-1][cells[i][1]-1] = 1;
        
        vector<vector<int>>Visited(row,vector<int>(col));
        queue<pair<int,int>>Q;
        
        for(int i = 0;i < col;i++)
            if(grid[0][i] == 0)
                Q.push({0,i});
            
        vector<int>dirx = {1,-1,0,0};
        vector<int>diry = {0,0,1,-1};
        
        while(!Q.empty()){
            int x = Q.front().first;
            int y = Q.front().second;
            Q.pop();
            
            if(x == row-1)return true;
            
            for(int  i = 0;i < 4;i++){
                int tempx = x + dirx[i];
                int tempy = y + diry[i];
                if(tempx >= 0 && tempy >= 0 && tempx < row && tempy < col)
                    if(Visited[tempx][tempy] == 0 && grid[tempx][tempy] == 0){
                        Q.push({tempx,tempy});
                        if(tempx == row-1)return true;
                        Visited[tempx][tempy] = 1;
                    }
            }
        }
        return false;
    }

    void resetVector(vector<vector<int>> &grid){
        for(int i = 0;i < grid.size();i++)
            for(int j = 0;j < grid[i].size();j++)
                grid[i][j] = 0;
    }
    
    public:
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        int low = 0,high = cells.size();
        int last_day_to_cross = 0;
        
        while(low <= high){
            int mid = (high + low) / 2;
            if(f(row,col,mid,cells)){
                low = mid + 1;
                last_day_to_cross = max(last_day_to_cross,mid);
            }
            else
                high = mid - 1;
        }
        
        return last_day_to_cross;
    }
};


int main() {
    vector<vector<int>> cells = {{1,2},{2,1},{3,3},{2,2},{1,1},{1,3},{2,3},{3,2},{3,1}};
    
    LastDay person;
    auto start = chrono::steady_clock::now();
    auto result = person.latestDayToCross(3,3,cells);
    auto end = chrono::steady_clock::now();

    cout << "Last day to cross: " << result << endl;
    cout << "...time taken: " << chrono::duration_cast<chrono::milliseconds>(end-start).count() << "ms";

    return 0;
}

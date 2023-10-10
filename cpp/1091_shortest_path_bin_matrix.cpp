#include <bits/stdc++.h>
using namespace std;


int val(int row, int col, int curr_min, int local_min){
	cout << "grid[" << row << "][" << col << "]: prev = " << local_min << ", new = " << curr_min << endl;
}

 int traverseAllPossible(vector<vector<int>>& grid,int row,int col,int &curr_min){
        if(grid[row][col]==1)
            return 201;

        if(row==grid.size()-1 && col==grid.size()-1)
            if(grid[row][col]==0)
                return 1;

        if(row+1<grid.size() && col+1<grid.size() && row+col+2<2*grid.size() && grid[row+1][col]==1 && grid[row][col+1]==1 && grid[row+1][col+1]==1)
            return 201;

        if((row+1>=grid.size() && col+1<grid.size() && grid[row][col+1]==1)||(col+1>=grid.size() && row+1<grid.size() && grid[row+1][col]==1))
            return 201;


        if(row+col+2<2*grid.size()){
            if(grid[row+1][col+1]==0){
                int local_min = curr_min;
                int min = 1+traverseAllPossible(grid,row+1,col+1,curr_min);
                val(row,col,curr_min,local_min);
                if(local_min<min)
                    min = local_min;
                curr_min+=1;
                if(min<curr_min)
                    curr_min = min;
                //return min;
            }
        }


        if(row+1<grid.size()){
            if(grid[row+1][col]==0){
                int local_min = curr_min;
                int min = 1+traverseAllPossible(grid,row+1,col,curr_min);
                val(row,col,curr_min,local_min);
                if(local_min<min)
                    min = local_min;
                curr_min+=1;
                if(min<curr_min)
                    curr_min = min;
                //return min;
            }
        }

        if(col+1<grid.size()){
            if(grid[row][col+1]==0){
                int local_min = curr_min;
                int min = 1+traverseAllPossible(grid,row,col+1,curr_min);
                val(row,col,curr_min,local_min);
                if(local_min<min)
                    min = local_min;
                curr_min+=1;
                if(min<curr_min)
                    curr_min = min;
                //return min;
            }
        }

        return curr_min;
    }

    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid[0].size();

        if(grid[0][0]!=0 || grid[n-1][n-1]!=0)
            return -1;

        int curr_min = 201;
        curr_min = traverseAllPossible(grid,0,0,curr_min);

        if(curr_min>199)
            return -1;
        return curr_min;
    }

    int main(){
		vector<vector<int>> grid = {{0,0,0},{0,1,0},{1,1,0}};
		cout << shortestPathBinaryMatrix(grid);

    	return 0;
	}

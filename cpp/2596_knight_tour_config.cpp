vector<int> checkNextTile(vector<vector<int>>& grid, int n, int i, int j){
        if(i+2<=n && j+1<=n && grid[i+2][j+1]==1+grid[i][j])
            return {i+2,j+1};
        if(i+2<=n && j-1>=0 && grid[i+2][j-1]==1+grid[i][j])
            return {i+2,j-1};
        //====================================================
        if(i+1<=n && j+2<=n && grid[i+1][j+2]==1+grid[i][j])
            return {i+1,j+2};
        if(i-1>=0 && j+2<=n && grid[i-1][j+2]==1+grid[i][j])
            return {i-1,j+2};
        //====================================================
        if(i-2>=0 && j+1<=n && grid[i-2][j+1]==1+grid[i][j])
            return {i-2,j+1};
        if(i-2>=0 && j-1>=0 && grid[i-2][j-1]==1+grid[i][j])
            return {i-2,j-1};
        //====================================================
        if(i+1<=n && j-2>=0 && grid[i+1][j-2]==1+grid[i][j])
            return {i+1,j-2};
        if(i-1>=0 && j-2>=0 && grid[i-1][j-2]==1+grid[i][j])
            return {i-1,j-2};
        
        return {-1,-1};
    }
    
    bool checkValidGrid(vector<vector<int>>& grid) {
        int n = (grid.size()*grid.size())-1,i=0,j=0;
        while(n>0){
            vector<int> ans = checkNextTile(grid,grid.size()-1,i,j);
            if(ans[0]==-1 && ans[1]==-1)
                return false;
            i=ans[0];
            j=ans[1];
            n-=1;
        }
        
        return true;
    }
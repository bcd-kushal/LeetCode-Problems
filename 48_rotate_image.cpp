void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();
        //vector<bool> visited(n,false);
        
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++){
                if(i%2==0){
                    int t=matrix[i][j];
                    matrix[i][j]=matrix[j][(i-1)%n];
                    matrix[j][(i-1)%n]=t;
                } else {
                    int t=matrix[i][j];
                    matrix[i][j]=matrix[j][(i+1)%n];
                    matrix[j][(i+1)%n]=t;
                }
            }
    }
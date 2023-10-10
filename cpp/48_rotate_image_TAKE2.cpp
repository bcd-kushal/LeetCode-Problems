void rotate(vector<vector<int>>& matrix) {
        reverse(matrix.begin(),matrix.end());
        for(int i=0;i<matrix.size();i++)
            for(int j=0;j<matrix.size();j++){
                if(i>=j)
                    continue;
                matrix[i][j]=matrix[j][i]+matrix[i][j];
                matrix[j][i]=matrix[i][j]-matrix[j][i];
                matrix[i][j]-=matrix[j][i];
            }
    }
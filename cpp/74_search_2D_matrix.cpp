bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows=matrix.size(),cols=matrix[0].size();
        int len=rows*cols;
        int low=0,high=len-1,mid;

        while(low<=high){
            mid=high+(low-high)/2;

            if(matrix[mid/cols][mid%cols]==target)
                return true;

            if(matrix[mid/cols][mid%cols]<target)
                low=mid+1;
            else
                high=mid-1;
        }

        return false;
    }

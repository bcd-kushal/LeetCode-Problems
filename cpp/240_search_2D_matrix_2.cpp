bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows=matrix.size(),cols=matrix[0].size();
        int i=0,low,high,mid;

        while(i<min(rows,cols)){
            if(target<=matrix[i][cols-1-i] && target>=matrix[i][0]){
                low=0,high=cols-1-i;
                while(low<=high){
                    mid=high+(low-high)/2;
                    if(target==matrix[i][mid])
                        return true;
                    if(target<matrix[i][mid])
                        high=mid-1;
                    else
                        low=mid+1;
                }
            }

            if(target>=matrix[i][cols-1-i] && target<=matrix[rows-1][cols-1-i]){
                low=i,high=rows-1;
                while(low<=high){
                    mid=high+(low-high)/2;
                    if(target==matrix[i][mid])
                        return true;
                    if(target<matrix[i][mid])
                        high=mid-1;
                    else
                        low=mid+1;
                }
            }

            i+=1;
        }

        return false;
    }

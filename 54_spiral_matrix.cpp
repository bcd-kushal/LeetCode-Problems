class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int rows=matrix.size(),cols=matrix[0].size();
        int count = 0,i=0,j=-1;

        vector<int> margin(4,0); //top right bottom left
        vector<int> order;

        while(count<=rows*cols){
            while(++j<cols-margin[1]){
                order.push_back(matrix[i][j]);
                ++count;
            }

            j-=1;
            margin[0]+=1;

            if(count>=rows*cols)
                break;
            //=========================================
            while(++i<rows-margin[2]){
                order.push_back(matrix[i][j]);
                ++count;
            }

            i-=1;
            margin[1]+=1;

            if(count>=rows*cols)
                break;
            //=========================================
            while(--j>=margin[3]){
                order.push_back(matrix[i][j]);
                ++count;
            }

            j+=1;
            margin[2]+=1;

            if(count>=rows*cols)
                break;
            //=========================================
            while(--i>=margin[0]){
                order.push_back(matrix[i][j]);
                ++count;
            }

            i+=1;
            margin[3]+=1;
            //=========================================

        }

        return order;
    }
};

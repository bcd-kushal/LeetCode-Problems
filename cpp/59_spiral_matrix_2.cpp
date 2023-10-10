class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {

        int count = 0,i=0,j=-1;

        vector<int> margin(4,0); //top right bottom left
        vector<vector<int>> order(n);

        for(;i<n;i++)
            order[i].resize(n);

        i=0;

        while(count<=n*n){
            while(++j<n-margin[1]){
                order[i][j]=count+1;
                ++count;
            }

            j-=1;
            margin[0]+=1;

            if(count>=n*n)
                break;
            //=========================================
            while(++i<n-margin[2]){
                order[i][j]=count+1;
                ++count;
            }

            i-=1;
            margin[1]+=1;

            if(count>=n*n)
                break;
            //=========================================
            while(--j>=margin[3]){
                order[i][j]=count+1;
                ++count;
            }

            j+=1;
            margin[2]+=1;

            if(count>=n*n)
                break;
            //=========================================
            while(--i>=margin[0]){
                order[i][j]=count+1;
                ++count;
            }

            i+=1;
            margin[3]+=1;
            //=========================================

        }

        return order;
    }
};

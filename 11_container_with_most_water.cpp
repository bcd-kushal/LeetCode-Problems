int maxArea(vector<int>& height) {
        int start=0,end=height.size()-1;
        int maxVol=0,currVol=0;

        while(start<end){
            currVol=(end-start)*min(height[start],height[end]);
            maxVol=max(maxVol,currVol);

            if(height[start]>height[end])
                end-=1;
            else if(height[start]<height[end])
                start+=1;
            else{
                start+=1;
                end-=1;
            }
        }

        return maxVol;
    }

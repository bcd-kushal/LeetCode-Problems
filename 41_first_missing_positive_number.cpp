int firstMissingPositive(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int shortest=1;
        for(auto x: nums){
            if(x<=0)
                continue;
            if(x==shortest)
                shortest+=1;
            else if(x<shortest)
                continue;
            else
                return shortest;
        }
        
        return shortest;
    }
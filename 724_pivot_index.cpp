int pivotIndex(vector<int>& nums) {
        if(nums.size()==1)
            return 0;
        
        int sum=0;
        for(auto num: nums)
            sum+=num;
        
        int curr_sum=0;
        for(int i=0;i<nums.size();i++){
            if(i!=0)
                curr_sum+=nums[i-1];
            
            if(sum-nums[i]-curr_sum==curr_sum)
                return i;
        }
        
        return -1;
    }
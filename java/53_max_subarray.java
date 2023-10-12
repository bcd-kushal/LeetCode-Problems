public int maxSubArray(int[] nums) {
        int global_max = Integer.MIN_VALUE;
        int local_max = 0;
        
        for(int i=0;i<nums.length;i++){
            local_max+=nums[i];
            global_max=Math.max(global_max,local_max);
            if(local_max<0)
                local_max=0;
        }
        
        return global_max;
    }
int maxSubArray(vector<int>& nums) {
        //kadane's algorithm
        int max_so_far=INT_MIN;
        int max_ending_here=0;

        for(auto num: nums){
            max_ending_here+=num;
            if(max_ending_here>max_so_far)
                max_so_far=max_ending_here;
            if(max_ending_here<0)
                max_ending_here=0;
        }

        return max_so_far;
    }

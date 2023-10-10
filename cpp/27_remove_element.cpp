int removeElement(vector<int>& nums, int val) {
        int k=0, fast=0;
        for(;fast<nums.size();fast++){
            if(nums[fast]==val){
                while(fast<nums.size() && nums[fast]==val)
                    ++fast;

            }
            if(fast<nums.size()){
                if(k!=fast)
                    nums[k]=nums[fast];
                k+=1;
            }
        }
        return k;
    }

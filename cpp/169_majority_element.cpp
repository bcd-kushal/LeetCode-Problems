int majorityElement(vector<int>& nums) {
        int limit=floor(nums.size()/2);
        unordered_map<int,int> hash;

        for(auto num:nums){
            hash[num]+=1;
            if(hash[num]>limit)
                return num;
        }

        return -1;
    }

vector<int> majorityElement(vector<int>& nums) {
        int limit=floor(nums.size()/3);
        unordered_map<int,int> hash;
        vector<int> ans;

        for(auto num:nums){
            if(hash[num]>limit)
                continue;

            hash[num]+=1;

            if(hash[num]>limit)
                ans.push_back(num);
        }

        return ans;
    }

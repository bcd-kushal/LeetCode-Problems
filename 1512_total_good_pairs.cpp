int numIdenticalPairs(vector<int>& nums) {
        int count=0;
        unordered_map<int,int> hash;

        for(auto num: nums)
            hash[num]+=1;

        for(auto x: hash)
            if(x.second>=2)
                count+=(x.second*(x.second-1))/2;

        return count;
    }

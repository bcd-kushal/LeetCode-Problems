vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> hash;
        vector<int> ans;

        int max_freq=-1,n=-1;

        for(auto num: nums)
            hash[num]+=1;


        while(k>0){
            for(auto x: hash){
                if(x.second>max_freq){
                    max_freq=x.second;
                    n=x.first;
                }
            }
            hash.erase(n);
            ans.push_back(n);
            max_freq=-1;
            n=-1;
            k-=1;
        }

        return ans;
    }

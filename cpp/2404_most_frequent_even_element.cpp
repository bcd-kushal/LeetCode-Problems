int mostFrequentEven(vector<int>& nums) {
        int mostFreq=nums[0];

        unordered_map<int,int> hash;
        if(nums[0]%2==0)
            hash[nums[0]]+=1;

        for(int i=1;i<nums.size();i++)
            if(nums[i]%2==0){
                hash[nums[i]]+=1;

                if(hash[mostFreq]<hash[nums[i]] || (hash[mostFreq]==hash[nums[i]] && nums[i]<mostFreq))
                    mostFreq=nums[i];
            }



        return (hash[mostFreq]==0)?-1:mostFreq;
    }

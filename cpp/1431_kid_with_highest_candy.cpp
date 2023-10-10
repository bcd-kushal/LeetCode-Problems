vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {        
        int max1=candies[0];
        
        for(int i=1;i<candies.size();i++)
            max1=max(max1,candies[i]);
        
        vector<bool> ans(candies.size(),false);
        
        for(int i=0;i<candies.size();i++)
            if(candies[i]==max1 || candies[i]+extraCandies>=max1)
                ans[i]=true;
        
        return ans;
    }
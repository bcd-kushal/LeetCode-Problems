vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        stack<int> st;
        vector<bool> ans(candies.size(),false);
        int maxCandy = candies[0];
        
        for(int i=0;i<candies.size();i++){
            if(maxCandy <= extraCandies+candies[i]){
                
                if(maxCandy < extraCandies+candies[i]){
                    while(!st.empty()){
                        ans[st.top()]=false;
                        st.pop();
                    }
                    
                    maxCandy = extraCandies+candies[i];
                }
                
                ans[i]=true;
                st.push(i);
            }
        }
        
        return ans;
    }
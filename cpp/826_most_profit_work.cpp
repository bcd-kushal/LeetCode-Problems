int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        unordered_map<int,int> hash;
        int max_profit_gained = 0;
        bool flag=true;
        
        for(int i=0;i<profit.size();i++)
            hash[difficulty[i]] = profit[i];
        
        sort(difficulty.begin(),difficulty.end());
        
        for(int i=0;i<worker.size();i++){
            
            if(worker[i]<difficulty[0])
                continue;
            
            for(int j=0;j<difficulty.size()-1;j++){
                if(worker[i]<=difficulty[j] && worker[i]>difficulty[j+1]){
                    max_profit_gained += hash[difficulty[j]];
                    flag=false;
                    break;
                }
            }
            
            if(flag)
                max_profit_gained += hash[difficulty[difficulty.size()-1]];
            
            flag=true;
        }
        
        return max_profit_gained;
    }
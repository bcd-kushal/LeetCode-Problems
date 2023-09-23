string mergeAlternately(string word1, string word2) {
        int n=min(word1.size(),word2.size());
        string ans="";
        
        for(int i=0;i<n*2;i++)
            ans+=(i%2==0)?word1[i/2]:word2[i/2];
        
        if(n<word1.size())
            ans+=word1.substr(n,word1.size());
        
        if(n<word2.size())
            ans+=word2.substr(n,word2.size());
        
        return ans;
    }
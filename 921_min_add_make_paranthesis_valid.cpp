int minAddToMakeValid(string s) {
        int lc=0, ans=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='(')
                lc++;
            if(s[i]==')'){
                if(lc>0)
                    lc--;
                else{
                    while(i<s.size() && s[i]==')'){
                        ans+=1;
                        i++;
                    }
                    i--;
                }
                    
            }
        }
        
        return ans+lc;
    }
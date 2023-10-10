int maxVowels(string s, int k) {
        int start=0,end=k-1,totalVowels=0,ans=0;
        for(;start<=end;start++)
            if(s[start]=='a'||s[start]=='e'||s[start]=='i'||s[start]=='o'||s[start]=='u')
                totalVowels+=1;
        start=0;
        ans=totalVowels;

        if(end==s.size()-1)
            return ans;

        for(int i=end;i<s.size();){
            if(s[i+1]=='a'||s[i+1]=='e'||s[i+1]=='i'||s[i+1]=='o'||s[i+1]=='u')
                totalVowels+=1;
            if(s[start]=='a'||s[start]=='e'||s[start]=='i'||s[start]=='o'||s[start]=='u')
                totalVowels-=1;

            start+=1;
            i+=1;

            ans=max(ans,totalVowels);
        }

        return ans;
    }

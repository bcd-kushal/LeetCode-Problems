bool isSubsequence(string s, string t) {
        int n = s.size(),j=0;

        if(n>t.size())
            return false;


        for(int i=0;i<t.size();i++){
            if(j==n)
                break;
            if(t[i]==s[j])
                ++j;
        }

        if(j==n)
            return true;

        return false;
    }

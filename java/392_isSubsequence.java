public boolean isSubsequence(String s, String t) {
        int i = 0;
        
        for(int j=0;j<t.length();j++){
            if(i<s.length() && s.charAt(i)==t.charAt(j))
                i+=1;
            
        }
        
        if(i==s.length())
            return true;
        
        return false;
    }
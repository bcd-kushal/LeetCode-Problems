string removeDuplicates(string s) {
        stack<char> st;
        st.push(s[0]);
        
        for(int i=1;i<s.size();i++){
            if(!st.empty() && s[i]==st.top())
                st.pop();
            else
                st.push(s[i]);
        }
        
        s = "";
        
        while(!st.empty()){
            s = st.top() + s;
            st.pop();
        }
        
        return s;
    }
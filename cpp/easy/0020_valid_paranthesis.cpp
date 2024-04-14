#include <bits/stdc++.h>
using namespace std;
 
class Paranthesis {
public:
    bool isValid(string s) {
        stack<char> st; 
        int n = s.size();   
  
        for(int i=0; i<n; i++) { 
            if(s[i]=='(' || s[i]=='{' || s[i]=='[')   
                st.push(s[i]); 
            else {
                if(st.empty())   
                    return false;
                char c = st.top(); 
                if((c=='(' && s[i]==')') || (c=='{' && s[i]=='}') || (c=='[' && s[i]==']'))
                    st.pop();
                else
                    return false; 
            }
        }
 
        return st.empty();
    }
};

int main() {
    string s = "(){[(()[]){}]()}";
    Paranthesis ob;

    auto start = chrono::steady_clock::now();
    cout << ob.isValid(s);
    auto end = chrono::steady_clock::now();
    cout << "\n... time taken: " << chrono::duration_cast<chrono::milliseconds>(end-start).count() << "ms";

    return 0;
}

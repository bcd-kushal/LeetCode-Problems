#include <string>
#include <stack>
using namespace std;

class Solution {
private:
    int key(char ch) {
        switch(ch) {
            case 'I': return 1;
            case 'V': return 5;
            case 'X': return 10;
            case 'L': return 50;
            case 'C': return 100;
            case 'D': return 500;
            case 'M': return 1000;
        }
        return 0;
    }

public:
    int romanToInt(string s) {
        stack<int> st;
        int value = 0;

        for(int i=0;i<s.size();i+=1) {
            if(st.empty())  st.push(key(s[i]));
            else {
                if(st.top() >= key(s[i]))
                    st.push(key(s[i]));
                else {
                    int x = key(s[i]) - st.top();
                    st.pop();
                    st.push(x);
                }
            }
        }

        while(!st.empty()) {
            value += st.top();
            st.pop();
        }

        return value;
    }
};
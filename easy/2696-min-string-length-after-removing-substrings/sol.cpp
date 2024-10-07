#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    int minLength(string s) {
        stack<pair<char, int>> st;
        string reduced = "";

        for (int i = 0; i < s.size();i+=1) {
            if(s[i]=='B' || s[i]=='D') {
                if(!st.empty() && ((st.top().first=='A' && s[i]=='B') || (st.top().first=='C' && s[i]=='D'))) {
                    s[st.top().second] = '#';
                    s[i] = '#';
                    st.pop();
                }
                else
                    st.push({s[i], i});
            }
            else
                st.push({s[i], i});
        }

        for (int i = 0; i < s.size();i+=1)
            if(s[i]!='#')
                reduced += s[i];

        return reduced.size();
    }
};
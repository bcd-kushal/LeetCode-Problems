#include <bits/stdc++.h>
using namespace std;

class MinStack {
    private:
        stack<pair<int,int>> st;

    public:
        MinStack() {
        }

        void push(int val) {    
            st.push(make_pair(val,min(val,st.empty() ? INT_MAX:st.top().second)));
        }

        void pop() {
            if(!st.empty())
                return st.pop();
        }

        int top() {
            if(!st.empty())
                return st.top().first;
            return 0;
        }

        int getMin() {
            if(!st.empty())
                return st.top().second;
            return 0;
        }
};

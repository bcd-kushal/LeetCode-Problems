#include <bits/stdc++.h>
using namespace std;

class MyStack {
    private:
        queue<int> q1;
        deque<int> q2;
    public:
        MyStack() {}
        int top() { return q1.empty() ? 0 : q1.front(); }
        bool empty() { return q1.empty() && q2.empty(); }
        
        void push(int x) {
            int a;
            if(!q1.empty()) {
                a = q1.front();
                q1.pop();
                q2.push_front(a);
            }
            q1.push(x);
        }
        
        int pop() {
            int popped_item = 0;
            if(!q1.empty()) {
                popped_item = q1.front();
                q1.pop();
                if(!q2.empty()) {
                    q1.push(q2.front());
                    q2.pop_front();
                }
            }
            return popped_item;
        }
};

int main() {
    MyStack *stack = new MyStack();
    stack->push(1);
    stack->push(2);
    cout << stack->top();
    cout << stack->pop();
    cout << stack->empty();

    return 0;
}
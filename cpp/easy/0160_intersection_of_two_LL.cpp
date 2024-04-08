#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
    public:
        ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
            ListNode *a = headA, *b = headB;
            while(a!=b) {
                a = a ? a->next : headB;
                b = b ? b->next : headA;
            }

            return a;
        }
};

int main() {
    Solution ob;

    auto start = chrono::steady_clock::now();
    ListNode *ans = ob.getIntersectionNode(new ListNode(2), new ListNode(12));
    auto end = chrono::steady_clock::now();

    cout << ans->val;
    cout << "\n...time taken: " << chrono::duration_cast<chrono::milliseconds>(end-start).count() << "ms";
    return 0;
}
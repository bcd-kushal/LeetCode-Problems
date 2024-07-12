#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Duplicates {
    public:
        ListNode* deleteDuplicates(ListNode* head) {
            if(!head)        return nullptr;
            if(!head->next)  return head;

            ListNode *ptr = head, *lead = head;
            while(lead) {
                if(lead->next && (lead->next->val != lead->val)){
                    if(ptr!=lead)
                        ptr->next = lead->next;
                    ptr = ptr->next;
                }

                if(!lead->next && ptr!=lead)
                    ptr->next = (ptr->val != lead->val) ? lead : nullptr;

                lead = lead->next;
            }

            return head;
        }
};

void printList(string desc, ListNode *head) {
    cout << endl << desc << " [ ";
    while(head) {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "nullptr ]";
}

int main() {
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2,new ListNode(3, new ListNode(3, new ListNode(3, new ListNode(4, new ListNode(4, new ListNode(5)))))));
    Duplicates dup;
    printList("Before:\t",head);

    auto start = chrono::steady_clock::now();
    head = dup.deleteDuplicates(head);
    auto end = chrono::steady_clock::now();

    printList("After:\t",head);
    cout << "\n... time taken: " << chrono::duration_cast<chrono::milliseconds>(end-start).count() << "ms";
    
    return 0;
}

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(!head || !head->next) 
          return head;
        
        ListNode *odd = head;
        ListNode *even = head->next;
        ListNode *evenHead = even;
                                    
        while(true) {
          if(even->next) {
            odd->next = even->next;
            odd = odd->next;
            even->next = nullptr;
          }
          else {
            odd->next = evenHead;
            break;
          }
          
          if(odd->next) {
            even->next = odd->next;
            even = even->next;
            odd->next = nullptr;
          }
          else {
            odd->next = evenHead;
            break;
          }
        }
        
        return head;
    }
};
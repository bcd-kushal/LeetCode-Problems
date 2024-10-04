using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lenDiff = 0;
        bool isFirstTaller;

        ListNode *ptrA = headA, *ptrB = headB;
        while(ptrA && ptrB) {
            ptrA = ptrA->next;
            ptrB = ptrB->next;
        }

        isFirstTaller = !ptrB ? true : false;
        ListNode *predecessor = isFirstTaller ? ptrA : ptrB;

        while(predecessor) {
            lenDiff += 1;
            predecessor = predecessor->next;
        }

        ptrA = headA;
        ptrB = headB;
        predecessor = isFirstTaller ? ptrA : ptrB;

        while(lenDiff>0) {
            predecessor = predecessor->next;
            lenDiff -= 1;
        }

        if(isFirstTaller)   ptrA = predecessor;
        else                ptrB = predecessor;

        while(ptrA && ptrB) {
            if(ptrA==ptrB)  return ptrA;
            ptrA = ptrA->next;
            ptrB = ptrB->next;
        }

        return nullptr;
    }
};
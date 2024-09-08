#include <vector>
#include <queue>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
private:

    struct SortLogic {
        bool operator()(const ListNode* a, const ListNode* b) {
            return a->val > b->val;
        }
    };

public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, SortLogic> heap;
        for(auto it: lists)
            if(it)
                heap.push(it);

        ListNode *sorted_list = new ListNode();
        ListNode *sorted_head = sorted_list;

        while(!heap.empty()) {
            ListNode *top = heap.top();
            heap.pop();

            sorted_list->next = new ListNode();
            sorted_list = sorted_list->next;
            sorted_list->val = top->val;

            if(top->next){
                top = top->next;
                heap.push(top);
            }
        }
        
        if(sorted_head->next)
            return sorted_head->next;
        return nullptr;
    }
};
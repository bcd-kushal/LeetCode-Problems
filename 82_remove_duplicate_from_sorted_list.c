/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteDuplicates(struct ListNode* head){
    if(!head)       return NULL;
    if(!head->next) return head;

    //struct ListNode *dummy_head;
    struct ListNode *p1=head, *p2=head->next;

    if(p1->val==p2->val){
        while(p2->next && p2->val==p2->next->val)
            p2=p2->next;
        p1=(p2->next)? p2->next:NULL;
        p2=(p2->next)? ((p2->next->next)?p2->next->next:p2->next):NULL;
        head=p1;
    }


    while(p2->next){
        if(p2->next && p2->val!=p2->next->val){
            p2=p2->next;
            p1=p1->next;
        }
        else{
            while(p2->next && p2->val==p2->next->val)
                p2=p2->next;
            p1->next = (p2->next)? p2->next:NULL;
            p2 = p1->next;
        }
    }

    return head;
}

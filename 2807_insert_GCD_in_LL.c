int getGCD(int a,int b){
    if(b!=0)
        return getGCD(b,a%b);
    return a;
}

struct ListNode* insertGreatestCommonDivisors(struct ListNode* head){
    struct ListNode *ptr = head;
    
    if(!ptr->next)
        return head;
    
    while(ptr->next){
        struct ListNode *temp = (struct ListNode*)malloc(sizeof(struct ListNode));
        temp->val = getGCD(ptr->val,ptr->next->val);
        temp->next = ptr->next;
        ptr->next = temp;
        ptr = ptr->next->next;
    }
    
    return head;
}
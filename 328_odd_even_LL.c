struct ListNode* oddEvenList(struct ListNode* head){
    if(!head)
        return NULL;
    
    struct ListNode *even_ptr=head;
    struct ListNode *odd_ptr=head->next;
    struct ListNode *y=head->next;
    
    if(!head->next)
        return head;
    
    
    struct ListNode *x=head;
    
    while(x->next->next || y->next->next){
        if(x->next->next){
            even_ptr->next=x->next->next;
            even_ptr=even_ptr->next;
            x=even_ptr;
        }
        
        if(y->next->next){
            odd_ptr=y->next->next;
            odd_ptr=odd_ptr->next;
            y=odd_ptr;
        }
    }
    
    x->next=head->next;
    
    return head;
}
ListNode* doubleIt(ListNode* head) {
        ListNode *ptr = head;
        
        if(ptr->val*2>=10){
            ListNode *t = new ListNode(1);
            t->next = head;
            head = t;
        }
        
        ptr->val = (ptr->val*2)%10;
        if(ptr->next && ptr->next->val>=5)
            ptr->val+=1;
        
        ptr = ptr->next;
        
        while(ptr){
            ptr->val = (ptr->val*2)%10;
            if(ptr->next && ptr->next->val>=5)
                ptr->val+=1;
            ptr = ptr->next;
        }
        
        return head;
    }
ListNode* mergeNodes(ListNode* head) {
        int localSum = 0;
        ListNode *t = head;
        ListNode *p = t;
        
        head = head->next;
        
        while(head){
            
            while(head && head->val!=0){
                localSum+=head->val;
                head = head->next;
            }
        
            head->val = localSum;
            t->next = head;
            t = head;
            localSum = 0;
            
            head = head->next;
        }
        
        return p->next;
    }
ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode *ptr1 = list1, *ptr2 = list2;
        a-=1;
        b+=1;
        int curr = 0;
        
        while(curr<a){
            curr++;
            ptr1 = ptr1->next;
        }
        
        ListNode *t = ptr1;
        
        while(curr<b){
            curr++;
            ptr1 = ptr1->next;
        }
        
        ListNode *s = ptr1;
        
        t->next = ptr2;
        
        while(ptr2->next)
            ptr2 = ptr2->next;
        
        ptr2->next = s;
        
        return list1;
    }
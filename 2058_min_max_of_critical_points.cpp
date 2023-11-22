vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int minNode = INT_MAX, maxNode = INT_MIN;
        vector<int> ans(2,-1);
        
        
        ListNode *ptr = head->next;
        ListNode *prev = head;
        
        while(ptr){
            if(ptr->next){
                if(prev->val<ptr->val && ptr->next->val<ptr->val)
                    maxNode = max(maxNode, ptr->val);
                
                if(prev->val>ptr->val && ptr->next->val>ptr->val)
                    minNode = min(minNode, ptr->val);
            }
            
            ptr = ptr->next;
            prev = prev->next;
        }
        
        ans[0] = (minNode==INT_MAX)? -1 : minNode;
        ans[1] = (maxNode==INT_MIN)? -1 : maxNode;
        
        return ans;
    }
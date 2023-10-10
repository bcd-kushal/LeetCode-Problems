int pairSum(ListNode* head) {
        if(!head)
            return NULL;
        
        int n=0;
        vector<int> twinSum;
        while(head){
            twinSum.push_back(head->val);
            head = head->next;
            n++;
        }
        
        int maxSum = INT_MIN;
        for(int i=0;i<=(n/2)-1;i++)
            maxSum = max(maxSum, twinSum[i] + twinSum[n-i-1]);
        
        return maxSum;
    }
ListNode* reverseList(ListNode* head) {
        stack<int> st;
        ListNode *ptr = head;
        while(ptr){
            st.push(ptr->val);
            ptr = ptr->next;
        }
        
        ptr = head;
        while(ptr){
            ptr->val = st.top();
            st.pop();
            ptr=ptr->next;
        }
        
        return head;
        
    }
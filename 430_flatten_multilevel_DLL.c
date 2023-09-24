Node* flatten(Node* head) {
        if(!head)
            return NULL;
        
        stack<Node*> st;
        
        Node *ptr = head;
        
        while(ptr){
            if(ptr->child){
                if(ptr->next)
                    st.push(ptr->next);
                else
                    st.push(NULL);
                
                ptr->next = ptr->child;
                ptr->child = NULL;
                ptr = ptr->next;
                continue;
            }
            
            if(ptr->next)
                ptr = ptr->next;
            else if(!st.empty()){
                ptr->next = st.top();
                st.pop();
                Node *temp = ptr;
                ptr = ptr->next;
                ptr->prev = temp;
            }
            else
                ptr->next = NULL;
        }
        
        return head;
    }
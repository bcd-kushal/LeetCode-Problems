public ListNode reverseList(ListNode head) {
        if(head==null)
            return null;
        
        Stack<Integer> st = new Stack();
        ListNode ptr = head;
        while(ptr!=null){
            st.push(ptr.val);
            ptr = ptr.next;
        }
        ptr = head;
        while(ptr!=null){
            ptr.val = st.pop();
            ptr = ptr.next;
        }
        
        return head;
    }
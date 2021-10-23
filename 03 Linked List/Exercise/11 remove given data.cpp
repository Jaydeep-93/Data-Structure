
        while (head && head->val == val) 
            head = head->next ; 
        ListNode * trav = head ; 
        while (trav ) {
            
            if (trav->next && trav->next->val == val) 
                trav->next = trav->next->next ; 
            else 
                trav = trav->next ; 
            
        }
        return head ; 
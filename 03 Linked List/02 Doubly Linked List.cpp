// Non Circular Doubly Linked List
#include <iostream> 
using namespace std ; 

class Node {
    public : 
        int info ; 
        Node * prev ; 
        Node * next ; 

    Node (int data) {
        this->info = data ; 
        this->prev = NULL ; 
        this->next = NULL ; 
    }
} ; 

class LinkedList {
    public : 
        Node * head ; 
    
    // creating linked list
    LinkedList() {
        head = NULL ; 
        addAtBegin(50) ;
        addAtBegin(40) ;
        addAtBegin(30) ;
        addAtBegin(20) ;
        addAtBegin(10) ;
    }

    // display entire linked list 
    void display () {
        Node * trav = head ; 
        cout << "list is : " ; 
        while (trav != NULL) {
            cout << trav->info <<" --> " ; 
            trav = trav->next ; 
        }
        cout << endl ; 
    }

    // count no of nodes in list 
    int count() {
        Node * trav = head ;
        int counter = 0 ; 
        while (trav != NULL) {
            counter++ ; 
            trav = trav->next ; 
        } 
        return counter ; 
    }

    // search for element 
    bool search (int data) {
        Node * trav = head ; 
        while (trav) {
            if (trav->info == data) 
                return true ; 
            trav= trav->next ; 
        }
        return false ; 
    } 

    // Add at begining 
    void addAtBegin (int data) {
        Node * temp = new Node(data) ; 
        temp->next = head ; 
        if (head) 
            head->prev = temp ; 
        head = temp ; 
    }

    // add at last
    void addAtLast (int data) {
        Node * trav = head ; 
        if ( trav == NULL) {
            addAtBegin(data) ; 
        } 
        else {
            Node * temp = new Node(data) ; 
            while (trav->next != NULL) 
                trav = trav->next ;
            temp->prev = trav ; 
            trav->next = temp ; 
        } 
    }
    
    // add before node 
    void addBeforeNode (int data , int item) {
        // id node exists ad before node else add at begin 
        Node * trav = head;
        
        while (trav) {
            if (trav->info == item) 
                break ; 
            trav = trav->next ; 
        }
        if (trav == NULL) {
            addAtBegin(data) ;
            return ;  
        } 
        Node * temp = new Node(data) ; 
        temp->prev = trav->prev ; 
        if (trav->prev != NULL)
            trav->prev->next = temp ; 
        else 
            head = temp ; 
        temp->next = trav ; 
        trav->prev = temp ; 
    } 

    // add after node 
    void addAfterNode (int data , int item) {
        // if item present add after node or add at last 
        Node * trav = head; 
        while (trav) {
            if (trav->info == item) 
                break ; 
            trav = trav->next ; 
        }
        if (trav == NULL) {
            addAtBegin(data) ; 
        }
        else { 
            Node * temp = new Node(data) ; 
            temp->next = trav->next ;
            if (trav->next != NULL)
                trav->next->prev = temp ;
            temp->prev = trav ; 
            trav->next = temp ; 
        }
    }

    // add node at position 
    void addAtPososition(int data, int position) { 
        if (position == 0 || head == NULL) {
            addAtBegin(data) ; 
        }
        else {
            // if count is greater that length add at last 
            Node * trav = head; 
            int counter = 0 ; 
            while (trav != NULL) {
                if (counter == position)
                    break ; 
                trav = trav->next ; 
                counter++ ; 
            }
            if (trav == NULL) 
                addAtLast(data) ; 
            else {
                Node * temp = new Node(data) ; 
                temp->next = trav ; 
                temp->prev = trav->prev ; 
                trav->prev->next = temp ; 
                trav->prev = temp ; 
            }
        }
    }

    // deleting first node 
    void delFirst() {
        Node * temp = head ; 
        head = head->next ; 
        head->prev = NULL ; 
        free(temp) ; 
    }

    // delete last node 
    void delLast(){
        Node * trav = head ;
        if (trav == NULL) 
            return ; 
        while (trav->next != NULL ) {
            trav = trav->next ; 
        }
        Node * temp = trav ;
        if (trav->prev) 
            trav->prev->next = NULL ;
        else 
            head = NULL ; 
        free(temp) ; 
        
    } 


    // search and delete 
    void deleteItem (int item) {
        if (head == NULL)
            return ;  
        else if (head->info == item)
            delFirst() ; 
        else {
            Node * trav = head ; 
            while (trav) {
                if (trav->info == item) 
                    break ; 
                trav = trav->next ; 
            }
            if (trav){
                Node * temp = trav ; 
                    trav->prev->next = trav->next ; 
                if (trav->next)
                    trav->next->prev = trav->prev ; 
                free(temp) ;
            } 
        }
    }

    // reverse list 
    void reverse () {
        Node * prev = NULL ; 
        Node * curr = head ; 
        Node * next = head ; 
        while (curr) {
            next = next->next ; 
            curr->next = prev ; 
            prev = curr ; 
            curr->prev = next ; 
            curr = next ;
        }
        head = prev ; 
    }
} ;


int main(){ 
    LinkedList list ; 
    
    // list.display() ;
    // cout << "No of nodes in list are : " << list.count() << endl ;  
    // cout << "35 present in list : " << list.search(35) << endl ; 
    // cout << "30 present in list : " << list.search(30) << endl ; 

    // list.addAtLast(60) ; 
    // list.display() ; 

    // list.addAfterNode(10,30) ; 
    // list.addAfterNode(20,10) ; 
    // list.display() ; 
 
    // list.addAtPososition(10,0) ; 
    // list.addAtPososition(20,1) ;
    // list.addAtPososition(30,55) ; 
    // list.display() ; 

    // list.delLast() ; 

    // list.addAtBegin(10) ; 
    // list.deleteItem(30) ; 
    // list.display() ; 

    list.display() ; 
    list.reverse() ; 
    list.display() ; 
}
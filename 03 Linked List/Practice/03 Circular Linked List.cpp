// Singly Circular Linked List 
#include <iostream>
using namespace std ; 

class Node {
    public : 
        int info ;
        Node * next ; 

        Node (int data) {
            this->info = data ; 
            this->next = NULL ; 
        } 
};
class LinkedList {
    public : 
        Node * last ; 

        // creation of linked list 
        LinkedList() {  
            this->last = NULL ; 
            addAtEnd(10) ;  
            addAtEnd(20) ;  
            addAtEnd(30) ;  
            addAtEnd(40) ;  
            addAtEnd(50) ;  
        }

        // display
        void display () {
            if (last == NULL){
                cout << "Empty List " << endl ; 
                return ; 
            }
            cout << "list is : " ; 
            Node * trav = last->next ; 
            do {
                cout << trav->info << " --> " ; 
                trav = trav->next ; 
            } while(trav != last->next) ;
            cout << endl ;  
        }

        // add to empty 
        void addToEmpty (int data){
            Node * temp = new Node(data) ;
            temp->next = temp ; 
            last = temp ; 
        }

        // add at begin
        void addAtBegin (int data) {
            if (last == NULL) 
                addToEmpty(data) ;
            else {
                Node * temp = new Node(data) ; 
                temp->next = last->next ; 
                last->next = temp ; 
            }
        }

        // add at end
        void addAtEnd (int data) {
            if (last == NULL) 
                addToEmpty(data) ; 
            else {
                Node * temp = new Node(data) ; 
                temp->next = last->next ; 
                last->next = temp ; 
                last = temp ; 
            }
        } 

        // add after node 
        void addAfterNode (int data , int item) {
            Node * trav = last->next ; 
            do {
                if (trav->info == item) 
                    break ; 
                trav = trav->next ; 
            }while (trav != last->next) ; 
            if (trav == last) 
                addAtEnd(data ) ; 
            else {
                Node * temp = new Node(data) ; 
                temp->next = trav->next ; 
                trav->next = temp ;
            } 
        }

        // delete node 
        void deleteNode (int item) {
            // delete only node 
            if (last->next == last) {
                last = NULL ; 
            }
            // delete last node of list
            else if (last->info == item){
                Node * trav = last->next ; 
                while (trav->next != last) 
                    trav = trav->next ; 
                Node * temp = trav->next ; 
                trav->next = last->next ; 
                last = trav ; 
                free(temp) ; 
            }
            // delete first node 
            if (last->next->info == item) {
                Node * temp = last->next ; 
                last->next = last->next->next ;
                free(temp) ;  
            }
            // any else node 
            else {
                Node * trav = last->next ; 
                while (trav != last) {
                    if (trav->next->info == item){
                        Node * temp = trav->next ; 
                        trav->next = trav->next->next ; 
                        free(temp) ; 
                    }  
                    trav = trav->next ; 
                }   
            }
        }

} ; 

int main() {
    LinkedList list ; 
    // list.addAfterNode(99,40) ; 
    // list.display() ; 


    list.deleteNode(30) ; 
    list.display() ; 
}
#include <iostream>     
using namespace std; 
                    
class ListNode{
    private:
        int data;
        ListNode *next;
    public:
        ListNode():data(0),next(0){};
        ListNode(int a):data(a),next(0){};
    friend class LinkedList;
};

class LinkedList{
    private:
        int size;
        ListNode *first;
    public:
        LinkedList():first(0){};
        void Traversal();
        void PushFront(int x);
        void PushBack(int x); 
        void Delete(int x);   
        void Clear();         
        void Reverse();   
        void GetSize();
};

void LinkedList::GetSize(){
    cout << this -> size << endl;
}

void LinkedList::Traversal(){
    if (first == 0) {
        cout << "List is empty.\n";
        return;
    }
    ListNode *current = first;             
    while (current != 0) {                 
        cout << current -> data << " ";
        current = current -> next;
    }
    cout << endl;
}

void LinkedList::PushFront(int x){
    ListNode *newNode = new ListNode(x);
    newNode -> next = first;              
    first = newNode;           
    this -> size ++;         
}

void LinkedList::PushBack(int x){
    ListNode *newNode = new ListNode(x);
    if (first == 0) {                   
        first = newNode;
        this -> size ++;         
        return;
    }
    ListNode *current = first;
    while (current -> next != 0) {           
        current = current -> next;
    }
    current -> next = newNode;   
    this -> size ++;            
}

void LinkedList::Delete(int x){
    ListNode *current = first,      
             *previous = 0;
    while (current != 0 && current -> data != x) {  
        previous = current;                       
        current = current -> next;                  
    } 
    if (current == 0) {
        cout << "Node not found.\n";
        return;
    } else if (current == first) {       
    	first = current -> next;          
        delete current;                 
        current = 0;       
        this -> size --;                  
        return;                     
    } else {                     
        previous -> next = current -> next;
        delete current;
        current = 0;
        this -> size --;            
        return;
    }
}

void LinkedList::Clear(){
    while (first != 0) {      
        ListNode *current = first;
        first = first -> next;
        delete current;
        current = 0;
    }
    this -> size = 0;            
}

void LinkedList::Reverse(){
    if (first == 0 || first -> next == 0) {
        return;
    }
    ListNode *previous = 0,
             *current = first,
             *preceding = first -> next;
    while (preceding != 0) {
        current -> next = previous;     
        previous = current;           
        current = preceding;          
        preceding = preceding->next;  
    }                                 
    current -> next = previous;         
    first = current;
}

int main(void) {
    LinkedList list;
    list.PushBack(0);
    list.PushBack(1); 
    list.PushFront(2);
    list.PushBack(3); 
    list.PushFront(4);
    list.Reverse();   
    list.Delete(3);   
    list.Traversal(); 
    return 0;
}
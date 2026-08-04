// BASICS //

#include<bits/stdc++.h>
using namespace std;


// creating a node
class Node{

    public:
    int data;
    Node*next;

    Node(){                   // assigning default values to node
        this->data = 0;
        this->next = NULL;
    }

    Node(int data){           // if data is given then assign it
        this->data = data;
        this->next = NULL;
    }

};


int findlength(Node* &head){     // finding length of linked list
    int len = 0;
    Node* temp = head;
    while(temp != NULL){
        temp = temp->next;
        len++;
    }
    return len;
}


void print(Node* head){        // printing linked list
    Node* temp = head;

    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}

///////////////////////////////////////////////////////////////////////////////// INSERTION ///////////////////////////////////////////////////////////////////////////

// insertion at head
void inserthead(Node* &head,Node* &tail,int data){

    if(head == NULL){                     // suppose if LL is empty then assign that node as head and tail
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
        return;
    }

    Node* newNode = new Node(data);        // otherwise insert the node at head
    newNode->next = head;
    head = newNode;

}

//insertion at tail
void inserttail(Node* &head,Node* &tail,int data){

    if(head == NULL){                      // suppose  if LL is empty then made that node as head & tail
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
        return;
    }

    Node* newNode = new Node(data);        // otherwise insert at tail
    tail->next = newNode;
    tail = newNode;
}


//insert at postion
void InsertAtPosition(Node* &head,Node* &tail,int data,int position){

    if(head == NULL){                    // suppose  if LL is empty then made that node as head & tail
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
        return;
    }

    int len = findlength(head);

    if(position == 0){                  // if given position points to head
        inserthead(head,tail,data);     // then insert at head
        return;
    }

    if(position >= len){              // if given position points at tail
        inserttail(head,tail,data);   // iinsert at tail
        return;
    }

    int i = 1;                        // otherwise insert at given postion
    
    // step 1. locate the position in LL
    Node* prev = head;
    while(i < position){
        prev = prev->next;
        i++;
    }

    Node* curr = prev->next;

    // create a node
    Node* newNode = new Node(data);

    // insert the node b/w both previous and current node
    newNode->next = curr;
    prev->next = newNode;

}


////////////////////////////////////////////////////////////////////////////////// DELETION ////////////////////////////////////////////////////////////////////////////
void deleteNode(int position,Node* &head,Node* &tail){
 
    if(head == NULL){                                // if Head is NULL then there is no LL
        cout<<"Cannot delete , LL is empty ";
        return;
    }

    if(position == 1){            // if position tend to head
        Node* temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
        return;
    }

    int len = findlength(head);

    // deleting last node
    if(position ==len){
        // step 1 : find previous
        int i = 1;
        Node* prev = head;
        while(i < position - 1){
            prev = prev->next;
            i++;
        }
        //step 2 :
        prev->next = NULL;
        //step 3:
        Node* temp = tail;
        //step 4 : 
        tail = prev;
        delete temp;
        return;
    }

    // deleting middle node
    int i = 1;
    // find prev node postion
    Node* prev = head;
    while(i < position){
        prev = prev->next;
        i++;
    }

    // find curr node position
    Node* curr = prev->next;
    //  then join previous to next of current
    prev->next = curr->next;
    // mark current as NULL to free it
    curr->next = NULL;
    // then delete the current node
    delete curr;

}


int main(){
    
    Node* head = NULL;
    Node* tail = NULL;

    inserthead(head,tail,20);  // insertion at head
    inserthead(head,tail,50);
    inserthead(head,tail,60);
    inserthead(head,tail,90);
    cout<<"Printing After Head Insertion : ";
    print(head);
    cout<<endl;

    inserttail(head,tail,100);  // insert at tail
    inserttail(head,tail,120);
    cout<<"Printing After Tail Insertion : ";
    print(head);
    cout<<endl;

    InsertAtPosition(head,tail,702,7);   // insert at position
    cout<<"Printing After Position Insertion : ";
    print(head);
    cout<<endl;
    cout<<"Head : "<<head->data<<endl;
    cout<<"Tail : "<<tail->data<<endl;

    deleteNode(7,head,tail);                  // deletion at head & tail
    cout<<"After Head or Tail Deletion : ";
    print(head);
    cout<<endl;

    deleteNode(2,head,tail);                     // deletion at middle
    cout<<"After Middle Node Deletion : ";
    print(head);
    cout<<endl;
    
    return 0;

}
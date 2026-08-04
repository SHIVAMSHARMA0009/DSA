/* Here We Are Given a Linked List we Have To Reverse it */

#include<bits/stdc++.h>
using namespace std;

class Node{
    
    public:
    int data;
    Node* next;

    Node(){
        this->data = 0;
        this->next = NULL;
    }
    Node(int data){
        this->data = data;
        this->next = NULL;
    }

};

void print(Node* &head){
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}

void InsertAtTail(Node* &head,Node* &tail,int data){

    Node* newNode = new Node(data);

    if(head == NULL){
        head = newNode;
        tail = newNode;
        return;
    }

    tail->next = newNode;
    tail = newNode;

}

/* the main approach is that we have to just point the pointer of current node to its previous node */

/* we will take NULL pointer of previous node ||  curr node which is at head */

/* IMPORTANT :: we will also take a foward node just after current node because when we will connect the next pointer of current node with previous node just to make
   sure we don't loose the contact of followed linked list */

/* we will keep updating the current and previous node ..... will return the previous node which will be at tail as the current would have been reached to NULL */


// approach 1 : through recursion  || S.C => O(n)
Node* Reverse_recursion(Node* &prev,Node* &curr){

    if(curr == NULL){
        return prev;
    }

    Node* forward = curr->next;
    curr->next = prev;

    return Reverse_recursion(curr,forward);

}



// approach 2 : through loop || S.C => O(1)
Node* reverseIterator(Node* &prev, Node *&curr){

    Node* forward;

    while(curr != NULL){
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }

    return prev;
}


int main(){

    Node* head = NULL;
    Node* tail = NULL;

    int n;
    cout<<"Enter No. Of Nodes : ";
    cin>>n;

    int data;
    cout<<"Enter The Values : ";
    for(int i=0;i<n;i++){
        cin>>data;
        InsertAtTail(head,tail,data);
    }

    cout<<"Printing LL : ";
    print(head);
    cout<<endl;

    Node* prev = NULL;
    Node* curr = head;

    head = reverseIterator(prev,curr);
    cout<<"Printing LL after Reversing : ";
    print(head);

    return 0;

}
// FINDING MIDDLE NODE OF LINKED LIST //

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

int get_length(Node* &head){
    Node* temp = head;
    int length = 0;
    while(temp != NULL){
        length++;
        temp = temp->next;
    }
    return length;
}

void print(Node* &head){

    Node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }

}

void insertAtTail(Node* &head,Node* &tail,int data){

    Node* newNode = new Node(data);

    if(head == NULL){
        head = newNode;
        tail = newNode;
        return;
    }

    tail->next = newNode;
    tail = newNode;

}


// finding middle node of linked list
int find_middleNode(Node* &head){

    // create a new node
    Node* temp = head;
    int i = 1;
    int len = get_length(head);
    int mid;

    if(len % 2 == 0){            // node for even length
        mid = len/2;
    }
    else{                       // node for odd length
        mid = (len/2) + 1;
    }
    
    while(i < mid){             // traversing temporary node to middle node
        temp = temp->next;
        i++;
    }

    return temp->data;

}

// 2-pointer approach [Tortoise algorithm ]

/* there will be two pointer (slow & fast) on head */

/* Fast will move +2 step & slow will move +1 step (will increment slow only if fast moves +2 step) ultimately slow will give middle index [Odd-length] */

/* In case of Even Lenght -> slow will give middle node */

Node* MiddleNode(Node* &head){
    if(head == NULL){
        cout<<"LL is Empty !!";
        return head;
    }

    if(head->next == NULL){
        return head;
    }

    Node* slow = head;
    // Node* fast = head;                               // this willgive second middle node
    Node* fast = head->next;                      // if we want first middle node  

    while(slow != NULL && fast != NULL){
        fast = fast->next;

        if(fast != NULL){       // suppose if we are standing at node previous to tail & if we move fast by +2 it will move NULL
            fast = fast->next;  //after increment +1 step fast is not NULL then increment another +1 step of fast
            slow = slow->next;  // then move +1 step of slow
        }
    }

    return slow;
}


int main(){

    Node* head = NULL;
    Node* tail = NULL;

    int n;
    cout<<"Enter The Number of Node of LL : ";
    cin>>n;

    int data;
    cout<<"Enter The Node's Data : ";
    for(int i=0;i<n;i++){
        cin>>data;
        insertAtTail(head,tail,data);
    }

    cout<<"Printing LL : ";
    print(head);
    cout<<endl;

    cout<<"The Length of  LL : "<<get_length(head)<<endl;

    cout<<"The Middle : "<<find_middleNode(head)<<endl;

    cout<<"The Middle Node By Pointer : "<<MiddleNode(head)->data<<endl;

    return 0;

}
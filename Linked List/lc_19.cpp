/* we are given a LL and an integer k , we have to delete last kth node */

#include<bits/stdc++.h>
using namespace std;

class Node{

    public:
    int data;
    Node* next;

    Node(){
        this->data = data;
        this->next = NULL;
    }

    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

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

void print(Node* &head){
    if(!head) return;

    Node* temp = head;
    while(temp){
        cout<<temp->data<<" ";
        temp = temp->next;
    }

}

int getlength(Node* &head){

    int len = 0;
    Node* temp = head;
    while(temp){
        len++;
        temp = temp->next;
    }
    return len;
}

/* 1st optimal approach  ||   T.C : O(n)   ||   S.C : O(1)   */

Node* deleteKth1(Node* &head,int k){

    if(!head) return nullptr;

    int len = getlength(head);                // calculate total length of LL
    int end_index = len - k;                  // find the prev node of last kth node

    if(k == len){                 // if k equal to length means head needs to be deleted
        Node* temp = head; 
        head = head->next;
        delete temp;
        return head;
    }

    Node* prev = head;                          // move prev pointer just before the last kth node 
    for(int i=1;i<end_index;i++){
        prev = prev->next;
    }

    Node* curr = prev->next;                   // break the link of last kth node and delete it for memory management
    prev->next = curr->next;
    delete curr;

    return head;                               // return head

}

/* 2nd optimal approach => just one-pass alternative by using slow-fast pointer */
Node* deleteKth2(Node* &head,int k){

    Node* dummy = new Node(0);                // take dummy to handle test cases like deleting head
    dummy->next = head;

    Node* fast = dummy;
    Node* slow = dummy;

    for(int i=0;i<=k;i++){             // first move fast pointer k+1 steps as we want the slow to stop just before last kth node
        fast = fast->next;
    }

    while(fast != NULL){           // now fast is on just before the last kth node  and now move slow & fast together by +1 step till fast = NULL
        fast = fast->next;
        slow = slow->next;
    }

    Node* target = slow->next;    // now break the link and delete last kth node
    slow->next = target->next;
    delete target;

    head = dummy->next;           // update the head
    delete dummy;                 // delete dummy node

    return head;
}

int main(){

    Node* head = NULL;
    Node* tail = NULL;

    int n;
    cout<<"Enter no. of nodes : ";
    cin>>n;

    int data;
    cout<<"Enter The Node Value : ";
    for(int i=0;i<n;i++){
        cin>>data;
        insertAtTail(head,tail,data);
    }

    cout<<"LL before deletion : ";
    print(head);
    cout<<endl;

    int k;
    cout<<"Enter The no. of last node : ";
    cin>>k;

    // Node* newHead1 = deleteKth1(head,k);
    // cout<<"LL after deletion (1st) : ";
    // print(newHead1);
    // cout<<endl;

    Node* newHead2 = deleteKth2(head,k);
    cout<<"LL after deletion (2nd) : ";
    print(newHead2);
    cout<<endl;

    return 0;

}
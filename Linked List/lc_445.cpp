/* we are given two linked list & add them */

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



void insertAtTail(Node* &head,Node* &tail,int data){

    Node* newNode = new Node(data);

    if(head ==NULL){
        head = newNode;
        tail = newNode;
        return;
    }

    tail->next = newNode;
    tail = newNode;

}



Node* reverse(Node* &head){      // first reverse the LL

    Node* forward;
    Node* curr = head;
    Node* prev = NULL;

    while(curr){
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }

    return prev;
}



Node* add(Node* &head1,Node* &head2){   // performing addition here

    Node* temp1 = head1;
    Node* temp2 = head2;
    int carry = 0;

    Node* dummy = new Node(-1);
    Node* tail = dummy;

    while(temp1 || temp2 || carry){

        int sum = carry;

        if(temp1){
            sum += temp1->data;
            temp1 = temp1->next;
        }

        if(temp2){
            sum += temp2->data;
            temp2 = temp2->next;
        }

        int digit = sum%10;
        carry = sum/10;

        tail->next = new Node(digit);
        tail = tail->next;
    }

    return dummy->next;

}

void print(Node* &head){           // print the added LL

    Node* temp = head;
    while(temp){
        cout<<temp->data<<" ";
        temp = temp->next;
    }

}


int main(){

    Node* head1 = NULL;
    Node* tail1 = NULL;

    Node* head2 = NULL;
    Node* tail2 = NULL;

    int n;
    cout<<"Enter no. of nodes in 1st LL : ";
    cin>>n;
    cout<<"Enter Node Data : ";
    int data;
    for(int i=0;i<n;i++){
        cin>>data;
        insertAtTail(head1,tail1,data);
    }

    int m;
    cout<<"Enter no. of nodes in 2nd LL : ";
    cin>>m;
    cout<<"Enter Node Data : ";
    for(int i=0;i<m;i++){
        cin>>data;
        insertAtTail(head2,tail2,data);
    }

    head1 = reverse(head1);                // reverse the both LL kyuki addition last digit se hota hai
    head2 = reverse(head2);

    Node* newHead = add(head1,head2);      // after reversing now add both the LL

    newHead = reverse(newHead);           // now reverse the modified LL as we have reversed the both the LL in above steps

    cout<<"The addition : ";
    print(newHead);

    return 0;
}
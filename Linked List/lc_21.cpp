/* we are given two sorted list , we have to merge them in sorted order */

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

    if(head == NULL){
        head = newNode;
        tail = newNode;
        return;
    }

    tail->next = newNode;
    tail = newNode;
}

void print(Node* &head){

    if(head == NULL){
        cout<<"Empty LL !!";
        return;
    }

    Node* temp = head;
    while(temp){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}

Node* mergeList(Node* &head1,Node* &head2){

    if(!head1 && !head2) return nullptr;   // base case 
    if(!head1) return head2;
    if(!head2) return head1;
    
    Node* ans = new Node(-1);         // dummy node
    Node* ptr = ans;                  // pointer to nodes

    while(head1 && head2){
        if(head1->data <= head2->data){    // compare value and add to dummy node
            ptr->next = head1;
            ptr = head1;
            head1 = head1->next;
        }
        else{
            ptr->next = head2;
            ptr = head2;
            head2 = head2->next;
        }
    }

    if(head1){                          // if any of LL is left , then join
        ptr->next = head1;
    }

    if(head2){
        ptr->next = head2;
    }

    return ans->next;

}

int main(){

    Node* head1 = NULL;
    Node* tail1 = NULL;

    Node* head2 = NULL;
    Node* tail2 = NULL;

    int n,m;
    int data;
    cout<<"Enter no. of nodes of 1st list : ";
    cin>>n;
    cout<<"Enter Node Value : ";
    for(int i=0;i<n;i++){
        cin>>data;
        insertAtTail(head1,tail1,data);
    }

    cout<<"Enter no. of nodes of 2nd list : ";
    cin>>m;
    cout<<"Enter Node Value : ";
    for(int i=0;i<m;i++){
        cin>>data;
        insertAtTail(head2,tail2,data);
    }

    Node* newHead = mergeList(head1,head2);
    cout<<"Sorted List After Merging : ";
    print(newHead);


    return 0;
}
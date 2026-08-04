/* we are given LL and an n integer , just the rotate the list from last nth node */

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

Node* rotate(Node* &head,int k){

    if(!head) return nullptr;

    int len = getlength(head);

    int actualk = k % len;

    if(actualk == 0) return head;

    int lastNodePos = len - actualk -1;
    Node* lastNode = head;

    for(int i=0;i<lastNodePos;i++){
        lastNode = lastNode->next;
    }

    Node* newHead = lastNode->next;
    lastNode->next = NULL;

    Node* it = newHead;
    while(it->next){
        it = it->next;
    }

    it->next = head;

    return newHead;
    
}


int main(){

    Node* head = NULL;
    Node* tail = NULL;

    int n;
    cout<<"Enter no. of nodes : ";
    cin>>n;

    int data;
    cout<<"Enter Node Value : ";
    for(int i=0;i<n;i++){
        cin>>data;
        insertAtTail(head,tail,data);
    }

    cout<<"LL before rotation : ";
    print(head);
    cout<<endl;

    int k;
    cout<<"Last Node No. : ";
    cin>>k;

    head = rotate(head,k);
    cout<<"LL after rotation : ";
    print(head);
    cout<<endl;

    return 0;

}
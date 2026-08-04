/* we are given the LL , two integer M & N , we have to delete N nodes after M nodes */

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


void deleteNodes(Node* &head,int M,int N){

    if(!head) return;

    Node* it = head;
    for(int i=0;i<M-1;i++){
        if(!it) return;         // if M nodes are not available
        it = it->next;
    }

    Node* MthNode = it;
    it = MthNode->next;

    for(int i=0;i<N;i++){
        if(!it) break;          // after M nodes, if N nodes are not available

        Node* temp = it->next;    // delete the N nodes here
        delete it;
        it = temp;
    }

    MthNode->next = it;       // after deleting N nodes connect the last Mth node with node after last Nth node
    deleteNodes(it,M,N);     //  recursive call to do the repetitive task

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

    int M,N;
    cout<<"Enter M nodes : ";
    cin>>M;
    cout<<"Enter N nodes : ";
    cin>>N;

    deleteNodes(head,M,N);

    cout<<"LL after deletion : ";
    print(head);
    cout<<endl;

    return 0;

}
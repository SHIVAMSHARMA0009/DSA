// Reversing Kth group Node Of Linked List //

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



Node* reversekNodes(Node* &head,int k){

    if(head ==  NULL){                    // if LL is empty then head will be NULL
        cout<<"LL is Empty !!"<<endl;
        return NULL;
    }

    int len = get_length(head);         // if value of k greater than length of LL then we can't reverse
    if(k > len){
        return head;
    }

    // step 1 : reverse k node of LL
    Node* prev = NULL;
    Node* curr = head;
    Node* forward = curr->next;

    int count = 0;                      // here we are reversing first k nodes
    while(count < k){
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
        count++;
    }

    // step 2 : now reverse followed kth group of nodes  -> through recursion

    if(forward != NULL){                        // this means we are still left with nodes which are ahead


        head->next = reversekNodes(forward,k);   /* we have reversed first k-nodes & when recursion will return the node of LL after reversing ahead k-nodes */
                                                 /* we have to join that node with [head of first k-ndodes] which head->next */


    }

    // step 3 : return head of  midified linked list   ||  after reversing the kth nodes of whole LL we have to return the head of modified LL which will be previous node
    return prev;

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

    head = reversekNodes(head,4);
    cout<<"LL after K-Nodes Reversing : ";
    print(head);
    cout<<endl;

    return 0;

}
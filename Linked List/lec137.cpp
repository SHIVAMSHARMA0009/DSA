//// DOUBLY LINKED LIST ////

#include<bits/stdc++.h>
using namespace std;

// creating node for doubly linked list
class Node{
    public:
    int data;
    Node* prev;
    Node* next;

    Node(){
        this->data = 0;
        this->prev = NULL;
        this->next = NULL;
    }

    Node(int data){
        this->data = data;
        this->prev = NULL;
        this->next = NULL;
    }
};

int findlength (Node* &head){
    Node* temp = head;
    int len = 0;
    while(temp != NULL){
        temp = temp->next;
        len++;
    }
    return len;
}

void print(Node* &head){
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}

//////////////////////////////////////////////////////////////////////////////////////// INSERTION ////////////////////////////////////////////////////////////////////////

// INSERTION AT HEAD
void insertAtHead(Node* &head,Node* &tail,int data){
    if(head == NULL){
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
        return;
    }

    Node* newNode = new Node(data);
    newNode->next = head;
    head->prev = newNode;
    head = newNode;
}

// INSERTION AT TAIL
void insertAtTail(Node* &head,Node* &tail,int data){
    
    // dll is empty
    if(head == NULL){
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
        return;
    }

    // dll is not empty
    Node* newNode = new Node(data);
    tail->next = newNode;
    newNode->prev = tail;
    tail = newNode;

}

// INSERTION AT POSITION
void InsertAtPosition(Node* &head,Node* &tail,int position,int data){

    // if dll is empty
    if(head == NULL){
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
        return;
    }

    // if position tends to head
    if(position == 1){
        insertAtHead(head,tail,data);
        return;
    }

    // if position tends to tail;
    int len = findlength(head);
    if(position >= len){
        insertAtTail(head,tail,data);
        return;
    }

    // previous node to locate the given position
    Node* prevNode = head;

    int i = 1;
    while(i < position - 1){
        prevNode = prevNode->next;
        i++;
    }

    // node followed to previous to insert newNode b/w them
    Node* curr = prevNode->next;

    // create new node
    Node* newNode = new Node(data);
    // join newNode to current node first
    newNode->next = curr;
    curr->prev = newNode;
    // then join previous to newNode
    prevNode->next = newNode;
    newNode->prev = prevNode;

}

//////////////////////////////////////////////////////////////////////////////////// DELETION //////////////////////////////////////////////////////////////////////////

void deleteFromPosition(Node* &head,Node* &tail,int position){
    // if DLL is empty
    if(head == NULL){
        cout<<"DLL is empty !!";
        return;
    }

    // is single node present
    if(head->next == NULL){
        Node* temp = head;
        head = NULL;
        tail = NULL;
        delete temp;
        return;
    }

    if(position == 1){
        Node* temp = head;
        head = head->next;
        temp->next = NULL;
        head->prev = NULL;
        delete temp;
        return;
    }

    int len = findlength(head);

    if(position > len){
        cout<<"Please Enter Valid Position !!";
        cout<<endl;
        return;
    }

    if(position == len){
        Node* temp = tail;
        tail = tail->prev;
        tail->next = NULL;
        temp->prev = NULL;
        delete temp;
        return;
    }

    int i = 1;
    Node* left = head;
    while(i < position - 1){
        left = left->next;
        i++;
    }

    Node* curr = left->next;
    Node* right = curr->next;

    left->next = right;
    right->prev = left;

    curr->next = NULL;
    curr->prev = NULL;

    delete curr;

}


int main(){
    Node* first = new Node(10);
    Node* second = new Node(20);
    Node* three = new Node(30);

    Node* head = first;
    Node* tail = three;

    first->next = second;
    second->prev = first;

    second->next = three;
    three->prev = second;

    print(first);
    cout<<endl;

    insertAtHead(head,tail,40);
    cout<<"DLL After head insertion : ";
    print(head);
    cout<<endl;

    insertAtTail(head,tail,702);
    cout<<"DLL after tail insertion : ";
    print(head);
    cout<<endl;

    InsertAtPosition(head,tail,3,9);
    cout<<"DLL after position Insertion : ";
    print(head);
    cout<<endl;

    deleteFromPosition(head,tail,2);
    cout<<"DLL After Deletion : ";
    print(head);
    cout<<endl;

    return 0;
}
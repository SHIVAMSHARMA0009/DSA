/* we are given an LL beginning and ending with 0 and there several integer b/w zeroes , just the integers and merge it as sum */

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

Node* mergeBtwZeroes(Node* &head){

    if(!head) return NULL;
    if(!head->next) return nullptr;

    Node* slow = head;                   // take two pointer fast -> looks for non-integer and adds up and slow -> update value equal to sum         
    Node* fast = head->next;

    Node* lastNode = NULL;            // to de-link the connection of lastnode after adding up the in-between integers

    int sum = 0;

    while(fast){
        if(fast->data !=0 ){        // if data is not zero then add it
            sum += fast->data;
        }
        else{
            slow->data = sum;        // else update data of slow
            lastNode = slow;         // now update lastnode & slow pointer 
            slow = slow->next;
            sum = 0;                  // updating sum
        }
        fast = fast->next;
    }

    Node* temp = slow;             // head of LL which we need to delete

    lastNode->next = NULL;          // de-linking the last node of required LL

    while(temp){
        Node* it = temp->next;    // now start deletion of LL not required
        delete temp;
        temp = it;
    }

    return head;

}

int main(){

    Node* head = NULL;
    Node* tail = NULL;

    int n;
    cout<<"Enter no. of nodes : ";
    cin>>n;

    int data;
    cout<<"Enter Node data : ";
    for(int i=0;i<n;i++){
        cin>>data;
        insertAtTail(head,tail,data);
    }

    cout<<"Before Merging : ";
    print(head);
    cout<<endl;

    Node* newHead = mergeBtwZeroes(head);

    cout<<"After Merging : ";
    print(newHead);
    cout<<endl;

    return 0;
     
}
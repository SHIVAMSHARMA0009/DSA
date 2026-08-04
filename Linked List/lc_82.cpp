/* We are given with sorted LL which has duplicates & we have to remove the duplicate nodes */

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
        cout<<"LL is empty !!";
        return;
    }

    Node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }

}


// T.C : O(n)   ||   S.C : O(1)
Node* removeDuplicates(Node* &head){

    if(head == NULL) return NULL;
    if(head->next == NULL) return head;

    Node* prev = NULL;
    Node* curr = head;
    bool duplex = false;

    while(curr != NULL){

        if((curr->next != NULL) && (curr->data == curr->next->data)){    // CASE 1 : nodes are equal -> delete the next node
            duplex = true;
            Node* temp = curr->next;                                  // update current pointer & delete the current node
            curr->next = curr->next->next;
            temp->next = NULL;
            delete temp;
        }

        else if(duplex){                                         // CASE 2 : earlier nodes were equal -> now delete curr node
            duplex = false;
            if(prev == NULL){                // IMP : suppose duplicates are present from head so update head
                head = curr->next;
            }
            else{                           // otherwise : connect previous node to next of current node
                prev->next = curr->next;
            }
            Node* temp = curr;               // update the current pointer & delete the current node
            curr = curr->next;
            temp->next = NULL;
            delete temp;
        }

        else{                                                // CASE 3 : otherwise not equal then update the pointers
            prev = curr;
            curr = curr->next;
        }
        
    }

    return head;

}

int main(){

    Node* head = NULL;
    Node* tail = NULL;

    int n;
    cout<<"Enter The Number of Nodes In LL : ";
    cin>>n;

    cout<<"Enter The Nodes Value : ";
    int data;
    for(int i=0;i<n;i++){
        cin>>data;
        insertAtTail(head,tail,data);
    }

    cout<<"LL with Duplicates : ";
    print(head);
    cout<<endl;

    Node* newHead = removeDuplicates(head);

    cout<<"LL without Duplicates : ";
    print(newHead);
    cout<<endl;

    return 0;

}
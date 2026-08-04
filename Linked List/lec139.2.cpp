/* given a LL which consist of 0's , 1's & 2's  then sort the LL */

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
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }

}



/* Brute Force ||   T.C : O(n)   ||  S.C : O(1) */

/* count the no. of zeroes , ones & twos and then replacing the nodes data from starting of LL */

Node* sort1(Node* &head){

    if(!head){
        cout<<"Empty LL";
        return NULL;
    }

    if(!head->next){
        return head;
    }

    int zeroes = 0;
    int twos = 0;
    int ones = 0;

    Node* temp = head;
    while(temp){
        if(temp->data == 0){
            zeroes++;
        }
        else if(temp->data == 1){
            ones++;
        }
        else{
            twos++;
        }
        temp = temp->next;
    }

    temp = head;

    while(zeroes){
        temp->data = 0;
        temp = temp->next;
        zeroes--;
    }

    while(ones){
        temp->data = 1;
        temp = temp->next;
        ones--;
    }

    while(twos){
        temp->data = 2;
        temp = temp->next;
        twos--;
    }

    return head;
}




/* optimal Approach ||   T.C : O(n)    || S.C : O(1)  */
Node* sort2(Node* &head){

    // step 1 : create 3 dummy  nodes for 0's , 1's & 2's
    Node* ZeroHead = new Node(-1);
    Node* ZeroTail = ZeroHead;

    Node* OneHead = new Node(-1);
    Node* OneTail= OneHead;

    Node* TwoHead = new Node(-1);
    Node* TwoTail = TwoHead;

    Node* curr = head;

    // step 3 : traverse LL , separate each node  and join them to their  respective dummy nodes
    while(curr){

        if(curr->data == 0){
            Node* temp = curr;
            curr = curr->next;
            temp->next = NULL;

            ZeroTail->next = temp;
            ZeroTail = temp;
        }

        else if(curr->data == 1){
            Node* temp = curr;
            curr = curr->next;
            temp->next = NULL;

            OneTail->next = temp;
            OneTail = temp;
        }

        else if(curr->data == 2){
            Node* temp = curr;
            curr = curr->next;
            temp->next = NULL;

            TwoTail->next = temp;
            TwoTail = temp;
        }

    }

    // step 3 : update the head of 1's & 2's dummy nodes
    Node* temp = OneHead;
    OneHead = OneHead->next;
    temp->next = NULL;
    delete temp;

    temp = TwoHead;
    TwoHead = TwoHead->next;
    temp->next = NULL;
    delete temp;

    // step 4 : now join the dummy nodes
    if(OneHead){
        ZeroTail->next = OneHead;
        if(TwoHead){
            OneTail->next = TwoHead;
        }
    }
    else{
        if(TwoHead){
            ZeroTail->next = TwoHead;
        }
    }

    // update the head of modified sorted LL
    temp = ZeroHead;
    ZeroHead = ZeroHead->next;
    temp->next = NULL;
    delete temp;

    return ZeroHead;
}




int main(){

    Node* head = NULL;
    Node* tail = NULL;

    int n;
    cout<<"Enter No. Nodes Of LL : ";
    cin>>n;

    int data;
    cout<<"Enter Nodes Value : ";
    for(int i=0;i<n;i++){
        cin>>data;
        insertAtTail(head,tail,data);
    }

    head = sort1(head);
    cout<<"Sorted LL by Replacing data : ";
    print(head);
    cout<<endl;

    head = sort2(head);
    cout<<"Sorted LL without data replacement : ";
    print(head);
    cout<<endl;

    return 0;
}
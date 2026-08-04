/* we are given a main LL and each node of main LL is linked with another LL in downward direction
   our task is to merge them in sorted order in horizontal way */

#include<bits/stdc++.h>
using namespace std;

class Node{

    public:
    int data;
    Node* next = NULL;
    Node* bottom = NULL;

    Node(){
        this->data = 0;
        this->next = NULL;
        this->bottom = NULL;
    }

    Node(int data){
        this->data = data;
        this->next = NULL;
        this->bottom = NULL;
    }
};

void insertBottom(Node* &head,int data){
    Node* newNode = new Node(data);
    Node* temp = head;
    while(temp->bottom){
        temp = temp->bottom;
    }
    temp->bottom = newNode;
}

void print(Node* head){
    Node* temp = head;
    while(temp){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}

Node* merge(Node* a,Node* b){              // this will traverse through LL attached to last two nodes and will merge them

    if(!a) return b;
    if(!b) return a;

    Node* ans = NULL;                       // take a NULL pointer

    if(a->data <= b->data){                 // compare the data & and store it to pointer
        ans = a;
        a->bottom = merge(a->bottom,b);     // and update the bottom pointer & look for merge from updated bottom pointer
                                            //  when merge will return node , then it will get attached to bottom of value stored at ans pointer
    }
    else{
        ans = b;
        b->bottom = merge(a,b->bottom);
    }

    return ans;                             // at last ans pointer will be head of merged - sorted LL

}

Node* flatten(Node* root){
    if(!root) return NULL;                                    // after last node of main LL , there will be no LL , it will return NULL

    Node* mergedLL = merge(root,flatten(root->next));         // this will call recursively every node of main LL & will reach the last node
                                                              // of main LL && merge will take place of from last LL and NULL;

    return mergedLL;
}

void printBottom(Node* head) {
    Node* temp = head;
    while(temp) {
        cout << temp->data << " ";
        temp = temp->bottom;
    }
    cout << endl;
}

int main(){

    Node* head = NULL;
    Node* tail = NULL;

    int n;
    cout<<"Enter No. of Main Nodes : ";
    cin>>n;

    for(int i=0;i<n;i++){

        int val;
        cout<<"Enter the value for "<<i+1<<" node : ";
        cin>>val;

        Node* newNode = new Node(val);

        if(!head){
            head = newNode;
            tail = newNode;
        }
        else{
        tail->next = newNode;
        tail = newNode;
        }

        int m;
        cout<<"Enter no. of nodes for "<<val<<" : ";
        cin>>m;

        cout<<"Enter bottom node value : ";
        for(int j=0;j<m;j++){
            int bval;
            cin>>bval;
            insertBottom(newNode,bval);
        }
    }

    cout<<"Printing Before sorting & merging : ";
    print(head);
    cout<<endl;

    cout<<"Printing After sorting & merging : ";
    Node* newHead = flatten(head);
    printBottom(newHead);

    return 0;

}
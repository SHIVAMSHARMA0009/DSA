/* merge k sorted lists */

/* HEAP APPROACH : push the head of lists into the min_heap & take dummy node and attach the top od head while traversing through lists */


#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        next = NULL;
    }
};

void insertAtTail(Node* &head,Node* &tail,int data) {

    Node* newNode = new Node(data);

    if(head == NULL) {
        head = newNode;
        tail = newNode;
        return;
    }

    tail->next = newNode;
    tail = tail->next;

}

class compare{
    public:
    bool operator()(Node* a,Node* b) {       // custom operator
        return a->data > b->data;
    }
};

Node* sortlists(vector<Node*>lists) {

    priority_queue<Node*,vector<Node*>,compare>pq;     // min_heap

    for(auto list : lists){
        if(list) pq.push(list);          //  pushing head of all the list into min_heap
    }

    Node* dummy = new Node(-1);
    Node* tail = dummy;

    while(!pq.empty()) {
        Node* small = pq.top();       // take smallest one which will be at the top of min_heap
        pq.pop();

        tail->next = small;           // join it to dummy node
        tail = tail->next;

        if(small->next){                // if there is next node in the current node -> then push that node into min_heap
            pq.push(small->next);
        }
    }

    return dummy->next;
}

int main () {

    int n;
    cout<<"Enter The No. of lists : ";
    cin>>n;

    vector<Node*>lists;
    for(int i=0;i<n;i++) {

        Node* head = NULL;
        Node* tail = NULL;

        cout<<"Enter "<<i+1<<" list : ";
        int data;
        cin>>data;

        while(data != -1){
            insertAtTail(head,tail,data);
            cin>>data;
        }

        lists.push_back(head);

    }


    Node* newhead = sortlists(lists);

    cout<<"The Sorted list : ";
    Node* temp = newhead;
    while(temp) {
        cout<<temp->data<<" ";
        temp = temp->next;
    }

    return 0;

}
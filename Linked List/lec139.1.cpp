/* we are given an unsorted LL , we have to remove the duplicates from the LL */

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



/* 1 - approach : Nested Loop  ||  S.C : O(1)   ||   T.C : O(n^2)   */

/* take 2 pointer , one is at head and other is at next of first & then traverse second and if value of both pointer matched the delete second */

Node* removeDuplicates1(Node* &head){

    if(head == NULL) return NULL;
    if(head->next == NULL) return head;

    Node* temp1 = head;
    Node* curr = temp1->next;

    while(temp1){

        Node* prev = temp1;
        curr = temp1->next;

        while(curr){
            if(temp1->data == curr->data){
                Node* copy = curr;
                prev->next = curr->next;
                curr = curr->next;
                copy->next = NULL;
                delete copy;
            }
            else{
                curr = curr->next;
                prev = prev->next;
            }
        }

        temp1 = temp1->next;
    }

    return head;

}



/* 2 - approach : HashMap ||   T.C : O(n)    ||   S.C : O(n)   */

/* take boolean map visited & if any node data is already visited then delete that node */
Node* removeDuplicates2(Node* &head){

    if(head == NULL) return NULL;
    if(head->next == NULL) return head;

    unordered_map<int,bool> seen;
    Node* curr = head;
    Node* prev = NULL;

    while(curr){
        if(seen[curr->data]){
            prev->next = curr->next;
            delete curr;
            curr = prev->next;
        }
        else{
            seen[curr->data] = true;
            prev = curr;
            curr = curr->next;
        }
    }
    return head;
}



/* 3 - approach : set   ||   T.C : O(n)    ||   S.C : O(n)   */
Node* removeDuplicates3(Node* &head){

    if(head == NULL) return NULL;
    if(head->next == NULL) return head;

    unordered_set<int>seen;
    Node* curr = head;
    Node* prev = NULL;

    while(curr){
        if(seen.find(curr->data) != seen.end()){
            prev->next = curr->next;
            delete curr;
            curr = prev->next;
        }
        else{
            seen.insert(curr->data);
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
    cout<<"Enter No. Nodes Of LL : ";
    cin>>n;

    int data;
    cout<<"Enter Nodes Value : ";
    for(int i=0;i<n;i++){
        cin>>data;
        insertAtTail(head,tail,data);
    }

    cout<<"LL with duplicates : ";
    print(head);
    cout<<endl;

    head = removeDuplicates1(head);
    cout<<"LL without duplicates (nested) : ";
    print(head);
    cout<<endl;

    head = removeDuplicates2(head);
    cout<<"LL without duplicates (map) : ";
    print(head);
    cout<<endl;

    head = removeDuplicates3(head);
    cout<<"LL without duplicates (set) : ";
    print(head);
    cout<<endl;

    return 0;
}
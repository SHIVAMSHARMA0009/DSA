/* we are given the LL , just sort them using merge sort */

#include<bits/stdc++.h>
using namespace std;

class  Node{

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
    while(temp){
        cout<<temp->data<<" ";
        temp= temp->next;
    }
}

Node* find_mid(Node* &head){                      // find the middle of LL

    if(!head || !head->next) return head;

    Node* slow = head;
    Node* fast = head->next;

    while(fast && fast->next){
        fast = fast->next->next;
        slow = slow->next;
    }

    return slow;
}

Node* merge(Node* &head1,Node* &head2){               // merge the linked list

    if(!head1 && !head2) return nullptr;
    if(!head1) return head2;
    if(!head2) return head1;

    Node* ans = new Node(-1);
    Node* ptr = ans;

    while(head1 && head2){
        if(head1->data <= head2->data){
            ptr->next = head1;
            ptr = head1;
            head1 = head1->next;
        }
        else{
            ptr->next = head2;
            ptr = head2;
            head2 = head2->next;
        }
    }

    if(head1){
        ptr->next = head1;
    }

    if(head2){
        ptr->next = head2;
    }

    return ans->next;
}

Node* sort(Node* &head){

    if(!head || !head->next) return head;

    Node* mid = find_mid(head);   // find middle of LL so that we can split the LL into two parts

    Node* left = head;            // left part of LL
    Node* right = mid->next;      // right part of LL
    mid->next = NULL;             // breaking the link from middle so that we can get two LL (left & right)

    left = sort(left);            // sorting both the parts
    right = sort(right);

    Node* newHead = merge(left,right);     // merging the both the parts after sorting

    return newHead;                         

}

int main(){
    
    Node* head = NULL;
    Node* tail = NULL;

    int data;

    int n;
    cout<<"Enter no. of nodes : ";
    cin>>n;
    cout<<"Enter The node's value : ";
    for(int i=0;i<n;i++){
        cin>>data;
        insertAtTail(head,tail,data);
    }

    Node* newHead = sort(head);

    cout<<"The List After Sorting : ";
    print(newHead);
    cout<<endl;

    return 0;
}
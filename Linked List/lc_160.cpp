/* we are given two LL we have to find their intersection point */

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

void print(Node* &head){
    if(head == NULL){
        cout<<"LL is Empty !!";
        return;
    }

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

Node* find_intersection(Node* &head1,Node* &head2){

    if(!head1 || !head2) return nullptr;    //if any head is null -> no intersection is there

    Node* a = head1;
    Node* b = head2;

    while(a && b){                        // Traverse both the pointers

        if(a == b) return a;              // CASE 1 : if LL are of equal length then return one pointer when they will meet
        a = a->next;
        b = b->next;
    }

    if(a == NULL){                      // CASE 2 : B is bigger

        int len_b = 0;                  // find extra length of 2nd LL
        while(b){
            len_b++;
            b = b->next;
        }

        while(len_b--) head2 = head2->next;       // then update the head of 2nd LL

    }
    else{

        int len_a = 0;                 // CASE 3 : A is bigger
        while(a){
            len_a++;                   // find extra length of 1st LL
            a = a->next;
        }

        while(len_a--) head1 = head1->next;   // then update the head of 1st LL

    }

    while(head1 != head2){                // after updating head , traverse the both the head ahead
        head1 = head1->next;              // their meeting point will be intersection point
        head2 = head2->next;
    }

    return head1;                           // now return any of head

}

int main(){
    
    Node* first = new Node(10);
    Node* second = new Node(20);
    Node* third = new Node(30);
    Node* fourth = new Node(40);
    Node* fifth = new Node(50);
    Node* sixth = new Node(60);
    Node* seventh = new Node(70);
    Node* eigth = new Node(80);
    Node* ninth = new Node(90);

    first->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = sixth;
    sixth->next = seventh;
    seventh->next = eigth;
    eigth->next = ninth;
    ninth->next = NULL;

    Node* first2 = new Node(101);
    Node* second2 = new Node(201);
    Node* third2 = new Node(301);

    first2->next = second2;
    second2->next = third2;
    third2->next = fourth;

    Node* newHead = find_intersection(first,first2);

    cout<<"The Intersection : ";
    print(newHead);
    cout<<endl;

    return 0;
}
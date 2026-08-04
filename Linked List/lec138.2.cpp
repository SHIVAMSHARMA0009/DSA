/* Detect & Delete Loop */
/* We are given a LL , we have to perform the 3 operation over the LL */

/* 1. Check loop is present or not */
/* 2. Find starting point of the of loop */
/* 3. then remove the loop */

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
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}




/* 1 : DETECT LOOP */

// 1- approach : Hashmap Approach => visiting every non-visited node and marking as visited so if we found any node as visited then loop is there
bool detect_hash(Node* &head){

    unordered_map<Node*,bool>visited;
    Node* temp = head;
    while(temp != NULL && visited[temp] != true){
        visited[temp] = true;
        temp = temp->next;
    }
    return visited[temp];

}

/* 
    2- approach : FCD [floyd cycle detection] => take 2-pointer at head , move one as +2 step and other as +1 step , if they meet loop is there
                   as during each pass of fast and slow , distance b/w them in anti-clockwise in loop will decremented by 1 each time 
*/

bool detect_fcd(Node* &head){
    Node* fast = head;
    Node* slow = head;

    while(fast != NULL && fast->next != NULL){
        fast = fast->next->next;
        slow = slow->next;

        if(slow == fast){
            return true;
        }
    }
    return false;
}




/* 2 : FIND STARTING POINT OF LOOP */
/*

 We will take 2-pointer fast-slow at the head by incrementing +2 & +1 steps respectively , at some point they will meet in-between the loop 
 and when they will meet we will put the slow-pointer at head & after increment both the pointer by +1 steps & when they will meet
 It will give the starting point of the loop 

*/
Node* find_starting(Node* &head){

    if(head == NULL){                   // if LL is empty
        cout<<"LL is Empty !!";
        return NULL;
    }

    Node* fast = head;                   // take both pointers at head
    Node* slow = head;

    while(fast != NULL && fast->next != NULL){    // meeting both the pointer
        fast = fast->next->next;
        slow = slow->next;
        if(slow == fast){   // place slow at head
            slow = head;
            break;
        }
    }

    while(slow != fast){    // now increment slow and fast by +1 steps
        fast = fast->next;
        slow = slow->next;
    }

    return slow;

}



/* 3 : REMOVE LOOP : just take prev pointer just before the fast & when fast will be at starting , we'll make previous->next = NULL */

void remove_loop(Node* head){
    
    if(head == NULL){                   // if LL is empty
        cout<<"LL is Empty !!";
        return;
    }

    Node* fast = head;                   // take both pointers at head
    Node* slow = head;

    while(fast != NULL && fast->next != NULL){    // meeting both the pointer
        fast = fast->next->next;
        slow = slow->next;
        if(slow == fast){   // place slow at head
            slow = head;
            break;
        }
    }

    Node* prev;              // take previous pointer
    while(slow != fast){    // now increment slow and fast by +1 steps
        prev = fast;
        fast = fast->next;
        slow = slow->next;
    }
    
    prev->next = NULL;     //make previous as NULL

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
    ninth->next = fifth;

    cout<<"Detect by map : "<<detect_hash(first)<<endl;
    cout<<"Detect by fcd : "<<detect_fcd(first)<<endl<<endl;

    cout<<"Starting Point of Loop : "<<find_starting(first)->data<<endl<<endl;

    remove_loop(first);
    cout<<"LL after removing loop : ";
    print(first);

    return 0;


}
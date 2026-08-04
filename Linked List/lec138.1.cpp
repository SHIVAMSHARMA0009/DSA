/* Given a LL -> check , it is circular or not */

#include<bits/stdc++.h>
using namespace std;

class Node{

    public:
    int data;
    Node* next = NULL;

    Node(){
        this->data = 0;
        this->next = NULL;
    }

    Node(int data){
        this->data = data;
        this->next = NULL;
    }

};

bool check_circular(Node* &head){

    // 1-approach : 1-pointer  || T.C : O(n)  || S.C : O(1)
    // we will start a pointer from next to head and if pointer becomes equal to head while traversing then LL is  circular

    Node* temp = head->next;
    while(temp != NULL && temp != head){
        temp = temp->next;
    }
    return temp == head;



    // 2-approach : slow-fast pointer approach [ floyd's cycle detection ]  || T.C : O(n)  || S.C : O(1)
    // move fast by +2 and then slow by +1 & if LL is circular both the pointer will meet otherwise not

    Node* slow = head;
    Node* fast = head;

    while(fast != NULL){

        fast = fast->next;
        if(fast != NULL){
            fast = fast->next;
            slow = slow->next;
        }

        if(slow == fast) return true;

    }
    return false;



    // 3-approach : map-approach  || T.C : O(n)  || S.C : O(n)
    // mark the address of each non-visted node as visited & if any visited found while traversing then LL will be circular

    unordered_map<Node*,bool>mp;
    Node* temp = head;
    while(temp != NULL && mp[temp] != true){
        mp[temp] = true;
        temp = temp->next;
    }
    return mp[temp];

}

void print(Node* &head){

    Node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }

}



int main(){

    Node* first = new Node(10);
    Node* second = new Node(20);
    Node* third = new Node(30);
    Node* fourth = new Node(40);

    first->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = NULL;

    cout<<"LL is circular or not ? "<<check_circular(first)<<endl;

    return 0;
}
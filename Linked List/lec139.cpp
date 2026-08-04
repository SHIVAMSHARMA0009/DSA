/* Check LL is palindrome or not */

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




/* APPROACH 1 : reverse the  LL and check the value of both thr LL   ||   T.C : O(n)   ||   S.C : O(n)   */
void insertAtHead(Node* &reverseHead,Node* &reverseTail,int data){    // reversing through inserting at head //

    Node* newNode = new Node(data);

    if(reverseHead == NULL){
        reverseHead = newNode;
        reverseTail = newNode;
        return;
    }

    newNode->next = reverseHead;
    reverseHead = newNode;

}

bool checkPalindrome(Node* &head,Node* &reverseHead){

    if(!head || head->next == NULL){
        return true;
    }

    Node* temp1 = head;
    Node* temp2 = reverseHead;

    while(temp1 != NULL){
        if(temp1->data != temp2->data){
            return false;
        }
        else{
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
    }

    return true;
}




/* APPROACH 2 : Copy the value of LL into array  ||   T.C : O(n)   ||   S.C : O(n)   */
bool checkThroughArray(Node* &head){

    vector<int>nums;
    if(head == NULL || head->next == NULL){
        return true;
    }

    Node* temp = head;
    while(temp != NULL){
        nums.push_back(temp->data);
        temp = temp->next;
    }

    int i = 0;
    int j = nums.size() - 1;
    while(i <= j){
        if(nums[i++] != nums[j--]){
            return false;
        }
    }
    return true;

}




/* OPTIMIZED APPROACH : reversed the original array from middle & compare value from middle and head     ||   T.C : O(n)   ||   S.C : O(1)   */
Node* reverse(Node* &head){

    if(!head) return NULL;
    if(head->next == NULL) return head;

    Node* prev = NULL;
    Node* curr = head;

    while(curr != NULL){
        Node* forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }

    return prev;
}

bool checkOptimized(Node* &head){

    if(!head || head->next == NULL){
        return true;
    }

    Node* slow = head;
    Node* fast = head->next;

    while(fast != NULL && fast->next != NULL){
        fast = fast->next->next;
        slow = slow->next;
    }

    slow->next = reverse(slow->next);

    Node* temp1 = head;
    Node* temp2 = slow->next;
    while(temp2 != NULL){
        if(temp1->data != temp2->data){
            return false;
        }
        else{
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
    }

    return true;
}




int main(){

    Node* head = NULL;
    Node* tail = NULL;

    int n;
    cout<<"Enter The Size Of LL : ";
    cin>>n;

    cout<<"Enter Node Value : ";
    int data;
    for(int i=0;i<n;i++){
        cin>>data;
        insertAtTail(head,tail,data);
    }

    cout<<"Printing Value : ";
    print(head);
    cout<<endl;

   // reversing the LL through copy
   Node* reverseHead = NULL;
   Node* reverseTail = NULL;
   Node* temp = head;
   while(temp != NULL){
    insertAtHead(reverseHead,reverseTail,temp->data);
    temp = temp->next;
   }

   cout<<"Printing Reversed : ";
   print(reverseHead);
   cout<<endl;

   cout<<"Is LL Palindrome ? "<<checkPalindrome(head,reverseHead);
   cout<<endl;



   // checking through array
   cout<<"Is LL Palindrome (array) ? "<<checkThroughArray(head);
   cout<<endl;



   // reversing from middle
   cout<<"Is Palindrome (Optimized) ? "<<checkOptimized(head);

   return 0;

}
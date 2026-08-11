/* 1. given BST convert it into  DOUBLY LINKED LIST */
/* 2. given sorted DLL , form BST */

#include<bits/stdc++.h>
using namespace std;

class Node{

    public:
    int data;
    Node* left;
    Node* right;

    Node(int data) {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }

};

Node* buildBST(Node* root,int data) {

    if(root == NULL) {
        root = new Node(data);
        return root;
    }

    if(root->data > data) {
        root->left = buildBST(root->left,data);
    }
    else{
        root->right = buildBST(root->right,data);
    }

    return root;

}

void takeInput(Node* &root) {

    int data;
    cin>>data;

    while(data != -1) {
        root = buildBST(root,data);
        cin>>data;
    }

}

void levelOrderTraveral(Node* root) {  

    if(root == NULL) return;

    queue<Node*>q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()) {

        Node* front = q.front();
        q.pop();

        if(front == NULL) {
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{

            cout<<front->data<<" ";

            if(front->left) q.push(front->left);
            if(front->right) q.push(front->right);

        }
    }

}

void print(Node* head,int &n) {

    Node* temp = head;
    
    while(temp != NULL) {
        n++;
        cout<<temp->data<<" ";
        temp = temp->right;
    }

}

// 1.    BST -> DLL
void convertToDLL(Node* root,Node* &head) {

    if(root == NULL) return;  // base case

    convertToDLL(root->right,head);     // goes deep towards left

    root->right = head;                  // connect root's right (next) to head
    if(head != NULL) head->left = root;  // if head is not null -> then connect it left (prev) to root     // DLL formed

    head = root;           // update the head of DLL

    convertToDLL(root->left,head);

}

// 2.    DLL to BST
Node* DLLtoBST(Node* &head,int n) {

    if(n <= 0 || head == NULL) return NULL;

    Node* leftNode = DLLtoBST(head,n/2);

    Node* root = head;    //  midnode as root;
    root->left = leftNode;    // connect root to left

    head = head->right;    // IMP : head should move towards right node just after mid node of  DLL (root)

    root->right = DLLtoBST(head,n-1-n/2);   // connect to right

    return root;
}

int main () {

    Node* root = NULL;
    cout<<"Enter Node Value : ";
    takeInput(root);

    cout<<"Printing Tree before DLL : "<<endl;
    levelOrderTraveral(root);

    Node* head = NULL;
    convertToDLL(root,head);

    int n = 0;
    cout<<"The DLL : ";
    print(head,n);
    cout<<endl;

    root = DLLtoBST(head,n);

    cout<<"Printing Tree After DLL : "<<endl;
    levelOrderTraveral(root);

    return 0;

}
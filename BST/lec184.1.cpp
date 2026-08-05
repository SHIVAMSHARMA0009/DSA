/* search the given key in the BST */

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

bool searching(Node* root,int key) {

    if(root == NULL) {                               // if root is null
        return false;
    }

    if(root->data == key) return true;             // match found

    if(root->data > key) {                          // search in left sub tree
        return (root->left,key);
    }
    else{                                         // search in right sub tree
        return searching(root->right,key);
    }
}

int main() {

    Node* root = NULL;
    cout<<"Enter Value : ";
    takeInput(root);

    int key;
    cout<<"Enter Key : ";
    cin>>key;

    cout<<"Is Present : "<<searching(root,key);

    return 0;

}
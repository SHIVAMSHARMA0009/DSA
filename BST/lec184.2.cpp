/* return the maximum and minimum element of BST */

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

Node* builBST(Node* root,int data) {

    if(root == NULL) {
        root = new Node(data);
        return root;
    }

    if(root->data > data) {
        root->left = builBST(root->left,data);
    }
    else{
        root->right = builBST(root->right,data);
    }
}

void takeInput(Node* &root) {

    int val;
    cin>>val;

    while(val != -1) {
        root = builBST(root,val);
        cin>>val;
    }
}

int find_min(Node* &root) {

    if(root == NULL) {
        return -1;
    }

    Node* temp = root;

    while(temp->left != NULL) {
        temp = temp->left;
    }

    return temp->data;
}

int find_max(Node* &root) {

    if(root == NULL) {
        return -1;
    }

    Node* temp = root;

    while(temp->right != NULL) {
        temp = temp->right;
    }

    return temp->data;
}


int main () {

    Node* root = NULL;
    cout<<"Enter Node Value : ";
    takeInput(root);

    cout<<"The Minimum : "<<find_min(root)<<endl;
    cout<<"The Maximum : "<<find_max(root);

    return 0;

}
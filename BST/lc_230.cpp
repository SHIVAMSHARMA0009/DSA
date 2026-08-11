/* we are given BST anf integer k  -> find the kth smallest element */

/* APPROACH 1 : store inorder as inorder of BST is sorted  , return kth element from starting */
/* APPROACH 2 : tarverse deep towards left while returning , decrement k , when k == 0 return that node */

#include<bits/stdc++.h>
using namespace std;

class Node {

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

Node* buidlBST(Node* &root,int data) {

    if(root == NULL) {
        root = new Node(data);
        return root;
    }

    if(root->data > data) {
        root->left = buidlBST(root->left,data);
    }
    else{
        root->right = buidlBST(root->right,data);
    }

    return root;
}

void takeInput(Node* &root) {

    int data;
    cin>>data;

    while(data != -1) {
        root = buidlBST(root,data);
        cin>>data;
    }
}

int k1(Node* &root,int &k) {    // inorder version of traversal  => LNR

    if(root == NULL) return -1;

    // L
    int leftAns = k1(root->left,k);

    if(leftAns != -1) return leftAns;

    // N
    k--;
    if(k == 0) {
        return root->data;
    }

    // R
    int rightAns = k1(root->right,k);
    return rightAns;

}

void inorder(Node* root,vector<int>&arr) {

    if(root == NULL) return;

    //  L -> N-> R
    inorder(root->left,arr);
    arr.push_back(root->data);
    inorder(root->right,arr);

}

int k2(Node* root,int k) {

    vector<int>arr;
    inorder(root,arr);

    int n = arr.size();

    return k <= n ? arr[k-1] : -1;

}


int main() {

    Node* root = NULL;
    cout<<"Enter Node : ";
    takeInput(root);

    int k;
    cout<<"Enter K Value : ";
    cin>>k;

    cout<<"The Kth Smallest Element : "<<k2(root,k)<<endl;

    cout<<"The Kth Smallest Element : "<<k1(root,k)<<endl;

    return 0;
     
}
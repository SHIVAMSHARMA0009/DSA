/* we are given two trees , we have to check , are these two similer ? */

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

Node* buildtree() {

    int val;
    cin >> val;

    if(val < 1) {
        return NULL;
    }

    Node* root = new Node(val);

    root->left = buildtree();
    root->right = buildtree();

    return root;
}

bool sameTree(Node* p,Node* q) {

    if(p == NULL && q == NULL)  return true;        // case 1 : both nodes are null -> then true
    if(p == NULL ||  q == NULL) return false;       // case 2 : if one of node is null -> then false

    bool currans = (p->data == q->data);           // root node ans

    bool leftans = true;
    bool rightans = true;

    if(p->left != NULL || q->left != NULL) {     // ans from left subtree
        leftans = sameTree(p->left,q->left);
    }

    if(p->right != NULL || q->right != NULL) {    // ans from right subtree
        rightans = sameTree(p->right,q->right);
    }

    return currans && leftans && rightans;               // return true if all three are okkk
}

int main() {

    cout<<"Enter Tree1 Data : ";
    Node* p = buildtree();
    cout<<"Enter Tree2 Data : ";
    Node* q = buildtree();

    cout<<"Are identical ? "<<sameTree(p,q)<<endl;

    return 0;
}
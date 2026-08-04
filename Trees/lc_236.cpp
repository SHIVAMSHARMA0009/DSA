/* Lowest Common Integer -> we are given two node of tree  -> return the lowest common ancestor(node) of both the given node */

#include<bits/stdc++.h>
using namespace std;

class Node{

    public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

// return root node of tree
Node* buildTree() {

    int data;
    cin>>data;

    if(data == -1) {
        return NULL;
    }
    else{
        Node* root = new Node(data);

        root->left = buildTree();     // 1st case solve rest recursion will see
        root->right = buildTree();
    }
}

Node* lowestCommomAncestor(Node* root,Node* p ,Node* q) {

    if(root == NULL) return NULL;

    if(root->data == p->data) return p;     // agr mile jaye toh node ko bhejo 
    if(root->data == q->data) return q;      

    Node* leftAns = lowestCommomAncestor(root->left,p,q);      // nhi toh left me check kro
    Node* rightAns = lowestCommomAncestor(root->right,p,q);    // right me check kro

    if(leftAns == NULL && rightAns == NULL) return NULL;         //  p & q mile hi nhi
    if(leftAns != NULL && rightAns == NULL) return leftAns;      // p & q dono left side me hai
    if(leftAns == NULL && rightAns != NULL) return rightAns;     // p & q dono right side me hai
    if(leftAns != NULL && rightAns != NULL) return root;        // p & q dono different side me hai

}

int main () {

    Node* root = buildTree();

    int val;
    cout<<"Enter P value : ";
    cin>>val;
    Node* p = new Node(val);

    int val1;
    cout<<"Enter P value : ";
    cin>>val1;
    Node* q = new Node(val1);


    cout<<"The Lowest Common Ancestor : "<<lowestCommomAncestor(root,p,q)->data;

    return 0;

}
/* return the lowest common ancestor of node p  and q in BST */

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

/* there will exist 4 cases :
   CASE 1 : both the node are on left side
   CASE 2 : both the node are on right side
   CASE 3 & 4 : one node is on right and other is at left -> means root is lca
*/
Node* lca(Node* root,Node* p,Node* q) {

    if(root == NULL) return NULL;

    if(root->data > p->data && root->data > q->data) {    // case 1
        return lca(root->left,p,q);
    }

    if(root->data < p->data && root->data < q->data) {   // case 2
        return lca(root->right,p,q);
    }

    return root;   // case 3 & 4

}


int main() {

    Node* root = NULL;
    cout<<"Enter The Tree Value : ";
    takeInput(root);

    int val;
    cout<<"Enter 1st Node : ";
    cin>>val;
    Node* p = new Node(val);

    int val2;
    cout<<"Enter 2nd Node : ";
    cin>>val2;
    Node* q = new Node(val2);

    cout<<"The Lowest Common Ancestor : "<<lca(root,p,q)->data;

    return 0;

}
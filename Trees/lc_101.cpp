/* we are given tree , there is mirror from root node , check both the sides are symmetrical or not ? */

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

bool issymmetric(Node* p,Node* q) {

    if(p == NULL && q == NULL)  return true;        // case 1 : both nodes are null -> then true
    if(p == NULL ||  q == NULL) return false;       // case 2 : if one of node is null -> then false

    bool currans = (p->data == q->data);           // root node ans

    bool leftans = true;
    bool rightans = true;

    if(p->left != NULL || q->left != NULL) {     // left node will be at right side in mirror
        leftans = issymmetric(p->left,q->right);
    }

    if(p->right != NULL || q->right != NULL) {    // right node will be at left side in mirror
        rightans = issymmetric(p->right,q->left);
    }

    return currans && leftans && rightans;               // return true if all three are okkk
}

int main() {

    cout<<"Enter Tree Data : ";
    Node* p = buildtree();

    cout<<"Is Symmetric ? "<<issymmetric(p->left,p->right)<<endl;

    return 0;
}
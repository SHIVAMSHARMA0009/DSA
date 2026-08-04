/* Find the kth ancestor node */

#include<bits/stdc++.h>
using namespace std;

class Node{

    public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        this->data = val;
        left = NULL;
        right = NULL;
    }

};

Node* buildTree() {

    int val;
    cin>>val;

    if(val == -1) {
        return NULL;
    }
    else {
        Node* root = new Node(val);
        root->left = buildTree();
        root->right = buildTree();
    }
}

bool kthAncestor(Node* root,int target,int &k) {

    if(root == NULL) return false;                  // reached the beyond the leaf node        
 
    if(root->data == target) {                         // if current value matches the target
        return true;
    }

    if(k == 0) return false;                           // invalid value of k

    bool leftAns = kthAncestor(root->left,target,k);      // check for left
    bool rightAns = kthAncestor(root->right,target,k);    // check for right

    if(leftAns || rightAns){                // if any of subtree gives result
        k--;                                // increment the value 
        if(k == 0){                                        
            cout<<"The Kth Ancestor : "<<root->data;         // k = 0 print kth data
            k = -1;                                      // immediately set k as negative so that value don't repeat
        }
    }


    return leftAns || rightAns;
}

int main () {

    Node* root = buildTree();

    int val;
    cout<<"Node Value : ";
    cin>>val;

    int k;
    cout<<"Value of K : ";
    cin>>k;

    kthAncestor(root,val,k);

    return 0;

}
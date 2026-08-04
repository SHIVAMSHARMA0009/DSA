/* given a binary tree , we have to check it balance or not */
/* means the depth of the two subtrees of every node never differs by more than one.*/

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
        right =NULL;
    }
};

Node*  buildTree() {

    int val;
    cin>>val;

    if(val < -10000 || val > 10000) {
        return NULL;
    }

    else{
        Node* root = new Node(val);

        root->left = buildTree();
        root->right = buildTree();
    }

}

int Height(Node* root) {

    if(root == NULL) return 0;                         // you reached the leaf node

    int leftHeight = Height(root->left);               // left sub-tree height 
    int rightHeight = Height(root->right);             // right sub-tree height

    int height = max(leftHeight,rightHeight) + 1;      // why +1  -> include current node

    return height;
}

bool isBalanced(Node* root) {

    if(root == NULL) {                   // you reached last & single node
        return true;
    }

    int leftHeight = Height(root->left);             // height of left sub-tree
    int rightHeight = Height(root->right);           // height of right sub-tree
    int abs_diff = abs(leftHeight-rightHeight);      // Their Difference

    if(abs_diff > 1){                   // if height > 1 => not balanced
        return false;
    }

    bool leftAns = isBalanced(root->left);        // now check for left sub-tree
    bool rightAns = isBalanced(root->right);      // then for right sub-tree

    if(leftAns == true && rightAns == true) {     // if both the subtree are balanced 
        return true;
    }

    return false;      

}

int main() {

    Node* root = buildTree();

    cout<<"Is Balanced : "<<isBalanced(root);

    return 0;

}